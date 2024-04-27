#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void fgetData(int *nombre, float **x, float **y); 
void gnuplot(char *f, char** func, int n);
void lagrange(float *x, float *y, int n, char** p);					// L'interpolation de Lagrange
void spline(float *x, float *y, int n, char** p, char*** func);		// Le spline cubique

/// La méthode de Ckolesky
void cholesky_y(int dim, float **A, float *b, float *y);
void cholesky_x(int dim, float **A, float *y, float *x);
void cholesky(int dim, float **A, float *b, float *x, float *y);

int main(){
	printf("\n");
/// Données utiliser
	float *x = NULL, 
	      *y = NULL;
	int nombre=0; 
    char *P=NULL;
	char **func=NULL;
	
	fgetData(&nombre, &x, &y);
	
/// Traitement 
	lagrange(x, y, nombre, &P);
	spline(x, y, nombre, &P, &func);
	
/// Lancement de gnuplot
	gnuplot(P, func, nombre);
	
	return 0;
}

void fgetData(int *nombre, float **x, float **y) {
	FILE *fp = NULL;
	float *x1 = NULL, 
	      *y1 = NULL;
	int n=0;
    char line[100];
	
	fp = fopen("./data_interpolation.txt", "r");
	if(fp == NULL){
		printf("Erreur de l'overture du fichier data_interpolation.txt");
		exit(1);
	}
	
	while(fgets(line, 100,fp)) n++;			//Pour compter le nombre de ligne dans le fichier data 
    rewind(fp);

	x1 = (float*)malloc(n*sizeof(float));
	y1 = (float*)malloc(n*sizeof(float));
	printf("n=%d\n", n);
	
	// Pour avoir les données dans le fichier data_interpolation.txt
	for(int i=0;i<n;i++) {
        fscanf(fp, "%f %f", &x1[i], &y1[i]);
        printf("%f %f\n", x1[i], y1[i]);
    }
	puts(""); 
	fclose(fp);

	*nombre = n;
	*x = x1;
	*y = y1;
}

void gnuplot(char *f, char **func, int n){
	FILE *gp = popen("gnuplot -persist", "w");

	printf("P(x)=%s\n", f);
	
	if(gp){										 // Si gnuplot est en marche
/// Paramètrage de gnuplot
		fprintf(gp, "set term qt size 600,500\n");
		fprintf(gp, "set xlabel 'y'\n");
		fprintf(gp, "set ylabel 'x'\n");
		fprintf(gp, "set yrange [-8:8]\n");
		fprintf(gp, "set xrange [-2:8]\n");
		fprintf(gp, "set xzeroaxis\n");
		fprintf(gp, "set yzeroaxis\n");
		fprintf(gp, "set loadpath './data.txt'\n");  // Pour connaître le fichier
		
/// Tracage de courbe
		fprintf(gp, "plot './data_interpolation.txt' ls 7 lc 'black' pointsize 1 with linespoints, %s lc 'blue', ", f);
		for(int i=0;i<n;i++) {
			fprintf(gp, " %s ", func[i]);
			if(i<n-1) 
				fprintf(gp, " : ");
		}
		fprintf(gp, "\n");
		fflush(gp);
		pclose(gp);
	}
}

/***************m********************************************
 * 															*
 * 				Interpolatio Lagrange				     	*	
 * 															*
 * **********************************************************/

void lagrange(float *x, float *y, int n, char** p){
    float d=0;
	char *f=NULL;

	printf("La methode la grange : \n");
    
    f = (char*)malloc(n*n*100*sizeof(char));
    strcpy(f, "");

    printf("Les valeurs des [x,y] sont: \n");
    for(int i=0;i<n;i++){
        printf("x=%g, y=%g\n", x[i], y[i]);
    }
    puts("\n");

	// Chercher le polinome solution 
    for(int i=0;i<n;i++){
		strcat(f, "((");
        for(int j=0;j<n;j++){
            if(i!=j){
                d=x[i]-x[j];
                sprintf(f, "%s((x-%g)/(%g))", f, x[j], d);
                if((n-1>j && n-1!=i) || (n-1==i && n-2>j)){
                    strcat(f, "*");
                }
            }
        }
		strcat(f, ")");
        sprintf(f, "%s*(%g))", f, y[i]);
        if(n-1 > i){
            strcat(f, "+");
        }
    }

	*p = f;
	
	puts("\n\n");
}

/***************m********************************************
 * 															*
 * 				Interpolatio spline cubique			     	*	
 * 															*
 * **********************************************************/

void spline(float *x, float *y, int n, char** p, char*** func) {
	printf("La methode de spline cubique : \n");
	int dim = (n-1);					/// Pour le dimension de la matrice A
	float **A = NULL;						// Pour la matrice A que l'on va resolver
	float *labda = NULL; 				/// Pour lebda_j pour former la matrice A 
	float *f = NULL;					/// Pour P_j pour former la matrice A
	float *yf = NULL;					/// Pour Y_j pour la reponse de la matrice A
	float d_j=0, d_j1=0;					// Pour la distance entre x[i] et x[i+1] ; x[i] et x[i-1] 
	float *a1 = NULL, *b1 = NULL;			// Utilier dans la resolution par CHOLESKY
	float *a = NULL, *b = NULL;			/// Pour le a et b dans la solution final
	char **function = NULL;				/// Pour le résultat finale

	printf("La dimension est : %d\n", dim);
	
// Allocation des variable utile et initialisation de 0
	A = (float**)malloc(dim*sizeof(float*));
	if(A != NULL) {
		for(int i=0;i<dim;i++) {
			A[i] = (float*)malloc(dim*sizeof(float));
		}
	}
	for(int i=0;i<dim;i++) for(int j=0;j<dim;j++) A[i][j]=0;

	labda = (float*)malloc(dim*sizeof(float));
	for(int j=0;j<dim;j++) labda[j]=0;
	f = (float*)malloc(dim*sizeof(float));
	for(int j=0;j<dim;j++) f[j]=0;
	yf = (float*)malloc(dim*sizeof(float));
	for(int j=0;j<dim;j++) yf[j]=0;

	a1 = (float*)malloc(dim*sizeof(float));
	for(int j=0;j<dim;j++) a1[j]=0;
	b1 = (float*)malloc(dim*sizeof(float));
	for(int j=0;j<dim;j++) b1[j]=0;

	a = (float*)malloc(dim*sizeof(float));
	for(int j=0;j<dim;j++) a[j]=0;
	b = (float*)malloc(dim*sizeof(float));
	for(int j=0;j<dim;j++) b[j]=0;
	
	function = (char**)malloc(dim*sizeof(char*));
	if(function!=NULL) {
		for(int i=0;i<dim;i++) {
			function[i] = (char*)malloc(1000*sizeof(char));
		}
	}

// Pour calculer le labda_j , P_j et Y_j
	for(int i=1;i<n-1;i++) {
		d_j = x[i+1]-x[i];
		d_j1 = x[i]-x[i-1];

		labda[i] = d_j/(d_j1+d_j);
		f[i] = 1-labda[i];
		yf[i] = ((6/(d_j1+d_j))*(((y[i+1]-y[i])/d_j)-((y[i]-y[i-1])/d_j1)));
	}

// Pour former la matrice A
	for(int i=0;i<dim;i++) {
		A[i][i] = 2;
		if(i<dim) {
			A[i][i+1] = labda[i+1];
		}
		if(i>0) {
			A[i][i-1] = f[i];
		}
	}

// Affichage de la 
	for(int i=0;i<n;i++)
	{
		printf("Y1[%d]=%f\n", i, yf[i]);
	}
	puts("\n");
	for(int i=0;i<dim;i++) {
		for(int j=0;j<dim;j++) {
			printf("%g\t", A[i][j]);
		}
		puts("");
	}

// Pour la résolution par la méthode de CHOLESKY
	cholesky(dim, A, yf, b1, a1);
	
// Affichage de la solution par la méthode de CHOLESKY
	puts("La vecteur S:");
	for(int i=0;i<n;i++)
	{
		printf("S[%d]=%f\n", i, b1[i]);
	}
	puts("\n");

// Pour le calcul de a et b dans la solution final
	for(int i=0;i<dim;i++) {
		d_j = x[i+1]-x[i];

		a[i] = (y[i]/d_j)-((b1[i])*((d_j)/6));
		b[i] = (y[i+1]/d_j)-((b1[i+1])*((d_j)/6));
	}

// Affichage de la a et b
	puts("La vecteur a: ");
	for(int i=0;i<dim;i++)
	{
		printf("a[%d]=%f\n", i, a[i]);
	}
	puts("\n");
	puts("La vecteur b: ");
	for(int i=0;i<dim;i++)
	{
		printf("b[%d]=%f\n", i, b[i]);
	}
	puts("\n");

// Mettre dans la variable final les resultats
	for(int i=1;i<n;i++) {
		if(i<n-1)
			sprintf(function[i-1], "(x<%f)?((1/(6*%f))*(((%f)*((%f-x)**3))+((%f)*((x-%f)**3)))+((%f)*(%f-x))+((%f)*(x-%f)))", x[i], d_j, b1[i-1], x[i], b1[i], x[i-1], a[i-1], x[i], b[i-1], x[i-1]);
		else
			sprintf(function[i-1], "((1/(6*%f))*((%f*((%f-x)**3))-((%f)*((x-%f)**3)))+((%f)*(%f-x))+((%f)*(x-%f)))", d_j, b1[i-1], x[i], b1[i], x[i-1], a[i-1], x[i], b[i-1], x[i-1]);
	}

	*func = function;  // Affectation de la résultat dans la variable
}

/***************m********************************************
 * 															*
 * 				Résolution par la méthode de cholesky     	*	
 * 															*
 * **********************************************************/

// Résolution de la première équation dans la méthode de CHOLESKY
void cholesky_y(int dim, float **A, float *b, float *y){
	for(int i=0; i<dim; i++)
	{
		float stmp=0;
		for(int j=0;j<i;j++)
		{
			stmp += (A[i][j]*y[j]);
		}
		y[i] = (b[i]-stmp)/A[i][i];
	}
}

// Résolution de la deuxième équation dans la méthode de CHOLESKY
void cholesky_x(int dim, float **A, float *y, float *x){
	for(int i=dim-1;0<=i;i--)
	{
		float stmp=0;
		for(int j=dim-1;i<j;j--)
		{
		  stmp += (A[j][i]*x[j]);
		}
		x[i] = (y[i]-stmp)/A[i][i];
	}
}

// La méthode de CHOLESKY
void cholesky(int dim , float **A, float *b, float *x, float *y){
	float sum=0;
	
/// Triangularisation inférieur du matrice A
	for(int i=0;i<dim;i++){
		for(int j=0;j<i;j++){
			sum = 0;
			for(int k=0;k<j;k++){
				sum += A[i][k]*A[j][k];
			}
			A[i][j] = (1/A[j][j])*(A[i][j]-sum);
		}
		sum = 0;
		for(int k=0;k<i;k++){
			sum += A[i][k]*A[i][k];
		}
		A[i][i] = sqrt(A[i][i]-sum);
	}
	
/// Resolution de la vecteur
	cholesky_y(dim, A, b, y);
	
/// Resolution de la vecteur
	cholesky_x(dim , A, y, x);
}
