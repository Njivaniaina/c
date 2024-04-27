#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void descente(float x0,float alpha);
float fp(float x);
float f(float x);
void gnuplot();

int whatToDo(float *x0, float *alpha);
int menu(float x0, float alpha);

int main() {
/// Déclaration des données utiles 
	float x0 = 6;
	float alpha = 0.02;
	int choix = 1;

	while(choix) {
		choix = whatToDo(&x0, &alpha);
	}	

/// Traitement	
	// descente(x0,alpha);
	
/// Affichage par gnuplot 
	// gnuplot();
	
	return 0;
}

void descente(float x0,float alpha){
	float x = x0;
	x0 = 0;
	FILE *file = NULL;
	
	file = fopen("points.txt","w");
	
	while(fabs(x0-x)>1e-7) {
		x0 = x;
		fprintf(file,"%f %f\n",x,f(x));
		x = x0 -alpha*fp(x0);
		// printf("x = %f\n",x);
	}
	fclose(file);	
}

float fp(float x){
	return (2*x*cos(x)-x*x*sin(x)-1)/10;
}	

float f(float x){
	return (x*x*cos(x)-x)/10;
}	
void gnuplot(){
	FILE *gp = popen("gnuplot -persist","w");
	
	if(gp){
		fprintf(gp,"set xrange [-6:8]\n");
		fprintf(gp, "set term qt size 500,400\n");
		fprintf(gp, "set title 'f(x) = ((x*x*cos(x)-x)/10)'\n");
		fprintf(gp, "set xlabel 'x'\n");
		fprintf(gp, "set ylabel 'y'\n");
		fprintf(gp, "set xzeroaxis\n");
		fprintf(gp, "set yzeroaxis\n");
		fprintf(gp,"plot 'points.txt' using 1:2 with linespoints pt 7 ps 1,((x*x*cos(x)-x)/10)\n");
		
		fflush(gp); 	 
		pclose(gp);
	}
}

int menu(float x0, float alpha) {
	int choix = 0;
	printf("\n\t\t--------------\n\t\t|    MENU    | \n\t\t--------------\n");
	printf("C'est un programme qui cherche le minimum de la fonction f(x)=(x*x*cos(x)-x)/10 par la methode de descante gradient.\n");
	printf("\nLa valeur de x initiale est x0 = %g, le pas est alpha = %g \n\n", x0, alpha);
	printf("\t1 - Trace en gnuplot.\n");
	printf("\t2 - Chager la valeur de x0 initiale.\n");
	printf("\t3 - Chager le valeur du pas.\n");
	printf("\t0 - Quitter le programme.\n");
	printf("Votre choix : ");scanf("%d", &choix);
	system("clear");
	return choix;
}

int whatToDo(float *x0, float *alpha) {
	int choix=1;
	
	choix = menu(*x0, *alpha);
	switch(choix){
		case 1:
			descente(*x0, *alpha);
			gnuplot();
			break;
			
		case 2:
			system("clear");
			printf("Entrer la valeur de x0 : ");
			scanf("%f", x0);
			system("clear");
			break;
			
		case 3:
			system("clear");
			printf("Entrer la valeur de alpha : ");
			scanf("%f", alpha);
			system("clear");
			break;
			
		case 0:
			break;
			
		default:
			choix = 4;
			break;
	}
	return choix;	
}
