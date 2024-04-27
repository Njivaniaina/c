#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fgetData(int *nombre, float **x, float **y); 
void gnuplot(float *x, float *y, int n, char *f);
void lagrange(float *x, float *y, int n, char** p);


int main(){
	printf("\n");
/// Données utiliser
	float *x = NULL, 
	      *y = NULL;
	int nombre=0; 
    char *P;
	
	fgetData(&nombre, &x, &y);
	
/// Traitement 
	lagrange(x, y, nombre, &P);
	
/// Lancement de gnuplot
	gnuplot(x, y, nombre, P);
	
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
	
	while(fgets(line, 100,fp)) n++;
    rewind(fp);

	x1 = (float*)malloc(n*sizeof(float));
	y1 = (float*)malloc(n*sizeof(float));
	printf("n=%d\n", n);

	for(int i=0;i<n;i++) {
        fscanf(fp, "%f %f", &x1[i], &y1[i]);
        printf("%f %f\n", x1[i], y1[i]);
    } 
	fclose(fp);

	*nombre = n;
	*x = x1;
	*y = y1;
}

void gnuplot(float *x, float *y, int n, char *f){
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
		
///Pour tracer les données (internal data bloc)
		fprintf(gp, "$data << EOF\n");
		for(int i=0;i<n;i++) {
			fprintf(gp, "%f %f\n", x[i], y[i]);
		}
		fprintf(gp, "EOF\n");
		
/// Tracage de courbe
		fprintf(gp, "plot $data using 1:2 ls 7 lc 'black' pointsize 1 with linespoints, %s lc 'blue'\n", f);
		fflush(gp);
		pclose(gp);
	}
}

void lagrange(float *x, float *y, int n, char** p){
    float d=0;
	char *f=NULL;
    
    f = (char*)malloc(n*n*100*sizeof(char));
    strcpy(f, "");

    printf("Les valeurs des [x,y] sont: \n");
    for(int i=0;i<n;i++){
        printf("x=%g, y=%g\n", x[i], y[i]);
    }
    puts("\n");

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
}
