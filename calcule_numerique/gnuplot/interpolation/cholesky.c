#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
