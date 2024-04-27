#ifndef __CHOLESKY__
#define __CHOLESKY__

void cholesky_y(int dim, float **A, float *b, float *y);
void cholesky_x(int dim, float **A, float *y, float *x);
void cholesky(int dim, float **A, float *b, float *x, float *y);

#endif