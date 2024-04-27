#include <stdio.h>
#include <stdlib.h>

void fgetData(int *nombre, float **x, float **y); 
void gnuplot();

int main(){
	printf("\n");
/// Données utiliser
	float *x = NULL, 
	      *y = NULL;
	int nombre; 
	
	fgetData(&nombre, &x, &y);
	
/// Traitement 
	
	
/// Lancement de gnuplot
	gnuplot();
	
	return 0;
}

void fgetData(int *nombre, float **x, float **y) {
	FILE *fp = NULL;
	float *x1 = NULL, 
	      *y1 = NULL;
	int n=0;
	
	fp = fopen("./data_interpolation.txt", "r");
	if(fp == NULL){
		printf("Erreur de l'overture du fichier data1.txt");
		exit(1);
	}
	
	while(fgets(NULL, 0,fp)) n++;
		
	rewind(fp);
	x1 = (float*)malloc(*nombre*sizeof(float));
	y1 = (float*)malloc(*nombre*sizeof(float));
	
	for(int i=0;i<*nombre;i++) fscanf(fp, "%f %f", &x1[i], &y1[i]); 
	fclose(fp);
	
	*nombre = n;
	*x = x1;
	*y = y1;
}

void gnuplot(){
	FILE *gp = popen("gnuplot -persist", "w");
	
	if(gp){										 // Si gnuplot est en marche
/// Paramètrage de gnuplot
		fprintf(gp, "set term qt size 600,500\n");
		fprintf(gp, "set xlabel 'y'\n");
		fprintf(gp, "set ylabel 'x'\n");
		fprintf(gp, "set yrange [-2:8]\n");
		fprintf(gp, "set xrange [-2:8]\n");
		fprintf(gp, "set xzeroaxis\n");
		fprintf(gp, "set yzeroaxis\n");
		fprintf(gp, "set loadpath './data.txt'\n");  // Pour connaître le fichier
		
/// Tracage de courbe
		fprintf(gp, "plot './data_interpolation.txt' ls 7 lc 'black' pointsize 1 with linespoints\n");
		fflush(gp);
		pclose(gp);
	}
}
