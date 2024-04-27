#include <stdio.h>
#include <stdlib.h>

void fgetData(int *dim, float **x, float **y, float *xmin, float *xmax, float *ymin, float *ymax); 
void gnuplot(int dim, float a, float b, float xmin, float xmax, float ymin, float ymax);
void gnuplot_ajust(int dim, float *x, float *y, float *a, float *b);

int main(){
	printf("Cette programme lancer le programme gnuplot qui fait la methode de moindre carree!!\n");
/// Données utiliser
	int dim;
	float *x=NULL, *y=NULL; 
	float xmin=0, xmax=0, 
	      ymin=0, ymax=0;
	float a=0, b=0;
	
	fgetData(&dim, &x, &y, &xmin, &xmax, &ymin, &ymax); // Pour avoir les x et y
	
/// Traitement 
	gnuplot_ajust(dim, x, y, &a, &b);
	
/// Lancement de gnuplot
	gnuplot(dim, a, b, xmin, xmax, ymin, ymax);
	
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
	
	printf("La dimmension est %d\n", dim);
	if(gp){										 // Si gnuplot est en marche
/// Paramètrage de gnuplot
		fprintf(gp, "set term qt size 500,400\n");
		fprintf(gp, "set title 'f(x) = %g + %g*x'\n", b, a);
		fprintf(gp, "set xlabel 'Temps (s)'\n");
		fprintf(gp, "set ylabel 'Valeurs'\n");
		fprintf(gp, "set yrange [%f:%f]\n", ymin, ymax+5);
		fprintf(gp, "set xrange [%f:%f]\n", xmin, xmax+1);
		fprintf(gp, "set xzeroaxis\n");
		fprintf(gp, "set yzeroaxis\n");
		fprintf(gp, "set loadpath './data.txt'\n");  // Pour connaître le fichier
		
/// Tracage de courbe
		fprintf(gp, "plot %f+%f*x lw 3 lc 'green' , './data.txt' ls 7 lc 'red' pointsize 1 with linespoints\n", b, a);
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
