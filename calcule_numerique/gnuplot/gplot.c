#include <stdio.h>

void gnuplot(float xmin, float xmax, float ymin, float ymax);

int main(){
	printf("Cette programme permet d'éxecuter le gnuplot en c");
	/// Parramètres
	float 	ymin=-2, ymax=3,
			xmin=-1, xmax=10;
	
	/// Traitement et lancement de gnuplot
	gnuplot(xmin, xmax, ymin, ymax);
	
	return 0;
}

void gnuplot(float xmin, float xmax, float ymin, float ymax){
	FILE *gp = popen("gnuplot -persist", "w");
	
	if(gp){ // Si gnuplot est en marche
/// Paramètrage de gnuplot
		fprintf(gp, "set term qt size 800,600\n");
		fprintf(gp, "set title 'Sin(x) et cos(x)'\n");
		fprintf(gp, "set xlabel 'Temps (s)'\n");
		fprintf(gp, "set ylabel 'Valeurs'\n");
		fprintf(gp, "set yrange [%f:%f]\n", ymin, ymax);
		fprintf(gp, "set xrange [%f:%f]\n", xmin, xmax);
		fprintf(gp, "set xzeroaxis\n");
		fprintf(gp, "set yzeroaxis\n");
		fprintf(gp, "set loadpath './data.txt'\n");  // Pour connaître le fichier
		
/// Tracage de courbe
		fprintf(gp, "plot './data.txt' ls 7 lc 'red' pointsize 3 with linespoints ,sin(x) lc 'green' lw 3, cos(x) lc '#FFF400' lw 4\n");
		fflush(gp);
		pclose(gp);
	}
}
