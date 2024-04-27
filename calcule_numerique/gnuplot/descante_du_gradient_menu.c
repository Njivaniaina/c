#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void fgetData(int *dim, float **x, float **y, float *xmin, float *xmax, float *ymin, float *ymax); 
void gnuplot(int dim, float a, float b, float xmin, float xmax, float ymin, float ymax);
void gnuplot_ajust(int dim, float *x, float *y, float *a, float *b);

float calcule_detA0(int dim, float *x, float *y, float a, float b);
float calcule_detA1(int dim, float *x, float *y, float a, float b);
void descent_du_gradient(int dim, float *x, float *y, float *A0, float *A1, float alpha, float *x0);

int menu(float *x0, float alpha);
int whatToDo(int dim,float *x,float *y,float *a,float *b,float *alpha,float xmin,float xmax,float ymin,float ymax, float *x0);

int main(){
	// printf("Cette programme lancer le programme gnuplot qui fait la methode de moindre carree!!\n");
/// Données utiliser
	int dim;
	float *x=NULL, *y=NULL; 
	float xmin=0, xmax=0, 
	      ymin=0, ymax=0;
	float a=-7, b=10;
	float alpha = 0.001;
	int choix = 1;
	float x0[2] = {1, 1};
	
	fgetData(&dim, &x, &y, &xmin, &xmax, &ymin, &ymax); // Pour avoir les x et y
	
/// Lancement du programme infinie
	while(choix){
		choix = whatToDo(dim, x, y, &a, &b, &alpha, xmin, xmax, ymin, ymax, x0);
	}
	
/// Traitement 
	// gnuplot_ajust(dim, x, y, &a, &b);
	
	// descent_du_gradient(dim, x, y, &a, &b, alpha, x0);
	
/// Lancement de gnuplot
	// gnuplot(dim, a, b, xmin, xmax, ymin, ymax);
	
	return 0;
}

void fgetData(int *dim, float **x, float **y, float *xmin, float *xmax, float *ymin, float *ymax){
	float *x1=NULL, *y1=NULL;
	FILE *fp = NULL;
	
	fp = fopen("./data1.txt", "r");
	if(fp == NULL){
		printf("Erreur de l'overture du fichier data1.txt");
		exit(1);
	}
	
	fscanf(fp, "%d", dim);  // Pour avoir la dimension 
	
	x1 = (float*)malloc(sizeof(float)*(*dim));
	if(x1==NULL) exit(1);
	y1 = (float*)malloc(sizeof(float)*(*dim));
	if(y1==NULL) exit(1);
	
	*xmin = -1; *xmax = -1;
	*ymin = -1; *ymax = -1;
	
	for(int i=0;i<*dim;i++){
		fscanf(fp, "%f, %f", &x1[i], &y1[i]);
		if(x1[i] > *xmax) *xmax=x1[i];
		if(x1[i] < *xmin) *xmin=x1[i];
		if(y1[i] > *ymax) *ymax=y1[i];
		if(y1[i] < *ymin) *ymin=y1[i];
	}
	
	*x = x1;
	*y = y1;
	
	fclose(fp);
}

void gnuplot(int dim, float a, float b, float xmin, float xmax, float ymin, float ymax){
	FILE *gp = popen("gnuplot -persist", "w");
	FILE *droit = fopen("./droit.txt", "r");
	
	printf("La dimmension est %d\n", dim);
	printf("f(x)=%f+%f*x\n", a, b);
	
	if(gp){										 // Si gnuplot est en marche
/// Paramètrage de gnuplot
		fprintf(gp, "set term qt size 600,500\n");
		fprintf(gp, "set title 'f(x) = %g + %g*x'\n", b, a);
		fprintf(gp, "set xlabel 'Temps (s)'\n");
		fprintf(gp, "set ylabel 'Valeurs'\n");
		fprintf(gp, "set yrange [%f:%f]\n", ymin, ymax+5);
		fprintf(gp, "set xrange [%f:%f]\n", xmin, xmax+1);
		fprintf(gp, "set xzeroaxis\n");
		fprintf(gp, "set yzeroaxis\n");
		fprintf(gp, "set loadpath './data.txt'\n");  // Pour connaître le fichier
		
		fprintf(gp, "plot");
		if(droit != NULL) {
			char text[200];
			while(fgets(text, 200, droit)) {
				char *p = strchr(text, '\n');
				*p = ' ';
				
			
		
/// Tracage de courbe
				fprintf(gp, " %s lw 2 lc 'red',", text);
			}
			fclose(droit);
		}
		fprintf(gp, " %f+%f*x lw 6 lc 'green' , './data.txt' ls 7 lc 'black' pointsize 0.7\n", a, b);
		fflush(gp);
		pclose(gp);
	}
}

void gnuplot_ajust(int dim, float *x, float *y, float *a, float *b){
	float sumx=0, sumy=0, sumx2=0, sumxy=0, det=0, detA0=0, detA1=0;

/// Calcule des sommes utiles
	for(int i=0;i<dim;i++) sumx += x[i];
	for(int i=0;i<dim;i++) sumy += y[i];
	for(int i=0;i<dim;i++) sumx2 += x[i]*x[i];
	for(int i=0;i<dim;i++) sumxy += x[i]*y[i];
	
	det = dim*sumx2 - sumx*sumx;  // Calcule la déterminant 
	detA0 = sumy*sumx2 - sumxy*sumx; // Calcule de la déterminant de A0
	detA1 = dim*sumxy - sumx*sumy;	// Calcule de la déterminant de A1
	
	*b = detA0/det;
	*a = detA1/det;
	
	printf(" a = %f \t b = %f\n", *a, *b);
}

float calcule_detA0(int dim, float *x, float *y, float a0, float a1){ // Calcule de la déterminant de A0
	float detA0 = 0;
	
	for(int i=0;i<dim;i++){
		detA0 += (y[i]-(a0+a1*x[i]));
	}
	detA0 *= -2;
	
	return detA0;
}

float calcule_detA1(int dim, float *x, float *y, float a0, float a1){ // Calcule de la déterminant de A1
	float detA1 = 0;
	
	for(int i=0;i<dim;i++){
		detA1 += (y[i]-(a0+a1*x[i]))*x[i];
	}
	detA1 *= -2;
	
	return detA1;
}

void descent_du_gradient(int dim, float *x, float *y, float *A0, float *A1, float alpha, float *x0){
	float 	r0 = 0, r1 = 0, 
			a0 = 0, a1 = 0;
	int compte = 0;
	FILE *droit = fopen("./droit.txt", "w");
	
/// Calcule de la première suite  
	r0 = x0[0]; r1 = x0[1];
	a0 = r0 - alpha*(calcule_detA0(dim, x, y, r0, r1));
	a1 = r1 - alpha*(calcule_detA1(dim, x, y, r0, r1));
	
/// Calcule en boucle
	while((fabs(a0-r0)+fabs(a1-r1)) > 1e-7){
		r0 = a0;
		r1 = a1;
		
		float detA0 = calcule_detA0(dim, x, y, r0, r1);
		float detA1 = calcule_detA1(dim, x, y, r0, r1);
		
		a0 = r0 - alpha*detA0;
		a1 = r1 - alpha*detA1;
		compte++;
		if(droit != NULL && compte%100 == 0) fprintf(droit, "%g+%g*x\n", a0, a1);
	}
	
/// Affectation des variables 
	*A0 = a0;
	*A1 = a1;
	if(droit != NULL)
		fclose(droit);
	
	printf("Le compteur est %d\n", compte);
}

int menu(float *x0, float alpha){
	int choix = 0;
	printf("\n\t\t--------------\n\t\t|    MENU    | \n\t\t--------------\n");
	printf("C'est un programme qui cherche la droite f(x)= a*x + b. On cherche les variables a et b par la methode de descante gradient. \n");
	printf("\nLe valeur de la vector initiale est [%g;%g], le pas est %g \n\n", x0[0], x0[1], alpha);
	printf("\t1 - Trace en gnuplot.\n");
	printf("\t2 - Chager la valeur de la vecteur initiale.\n");
	printf("\t3 - Chager le valeur du pas.\n");
	printf("\t0 - Quitter le programme.\n");
	printf("Votre choix : ");scanf("%d", &choix);
	system("clear");
	return choix;
}

int whatToDo(int dim,float *x,float *y,float *a,float *b,float *alpha,float xmin,float xmax,float ymin,float ymax, float *x0){
	int choix=1;
	
	choix = menu(x0, *alpha);
	switch(choix){
		case 1:
			printf("Tracage de la droite sur gnuplot.\n\n");
			descent_du_gradient(dim, x, y, a, b, *alpha, x0);
			gnuplot(dim, *a, *b, xmin, xmax, ymin, ymax);
			break;
			
		case 2:
			printf("Entrer x et y successivement : ");
			scanf("%f %f", &x0[0], &x0[1]);
			system("clear");
			printf("Changement reussie. La valeur de vectuer initial est de [%g;%g]\n", x0[0], x0[1]);
			break;
			
		case 3:
			printf("Entrer la valeur de alpha: ");
			scanf("%f", alpha);
			system("clear");
			printf("Changement reussie. La valeur de l'alpha est %g\n", *alpha);
			break;
			
		case 0:
			break;
			
		default:
			choix = 4;
			break;
	}
	return choix;	
}
