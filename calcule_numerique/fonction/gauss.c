#include <stdio.h>
#include <stdlib.h>

//void getData(int *dim, float ***A, float **b, float **x);
void getDataf(int *dim, float ***A, float **b, float **x);
void displayResult(float *x, int dim, float *b, float **A);
void gauss(float **A, float *b, float *x, int dim);
void cleanup(float **A, float *b, float *x, int dim);
void triangularisation(float **A, int dim);

int main()
{
  printf("Resolution de A.b=x par la méthode de Gauss.\n");
// Entrer des données
  int dim=1;
  float **A=NULL;                 //addresse de la matrice du problème
  float *b=NULL;                  //addresse du vecteur seconde
  float *x=NULL;                  //addresse du vecteur solution
  getDataf(&dim, &A, &b, &x);            // donné à getData les addresses à utiliser
  
// Traitement des données
  gauss(A, b, x, dim);

// Sortie de résultat 
  displayResult(x, dim, b, A);

// Netoyage des espaces alloués dynamiquement
  cleanup(A, b, x, dim);

  return 0;
}
/*
void getData(int *dim, float ***A, float **b, float **x)
{
  printf("Voici les données!!!\n");
  float *v = NULL,
        **M = NULL,
        *s = NULL;

  *dim = 4;

  v = malloc(*dim*sizeof(float));
  if(v == NULL) 
  {
    cleanup(M, s, v, *dim);
    exit(1);
  }
  for(int i=0;i<*dim;i++) v[i]=i;

  s = malloc(*dim*sizeof(float));
  if(s == NULL)
  {
    cleanup(M, s, v, *dim);
    exit(1);
  }
  for(int i=0;i<*dim;i++) s[i]=i-1.78;

  M = (float**)malloc(*dim*sizeof(float*));
  if(M == NULL) 
  {
    cleanup(M, s, v, *dim);
    exit(1);
  }
  for(int i=0;i<*dim;i++)
  {
    M[i] = NULL;
    M[i] = (float*)malloc(*dim*sizeof(float)) ;
    if(M[i] == NULL)
    {
      cleanup(M, s, v, *dim);
      exit(1);
    }
  }
  for(int i=0;i<*dim;i++)
  {
    for(int j=0;j<*dim;j++)
    {
      M[i][j] = i+j;
    }
  }
  
  *x = v;
  *b = s;
  *A = M;
}
*/

void getDataf(int *dim, float ***A, float **b, float **x)
{
  float *v = NULL,
        **M = NULL,
        *s = NULL;
  FILE *pf = NULL;
  
  pf = fopen("./data_example.txt", "r");
  if( pf == NULL) exit(1);

  fscanf(pf, "%d", dim);

  M = (float**)malloc(*dim*sizeof(float*));
  if(M == NULL) 
  {
    cleanup(M, s, v, *dim);
    exit(1);
  }
  for(int i=0;i<*dim;i++)
  {
    M[i] = NULL;
    M[i] = (float*)malloc(*dim*sizeof(float)) ;
    if(M[i] == NULL)
    {
      cleanup(M, s, v, *dim);
      exit(1);
    }
  }
  for(int i=0;i<*dim;i++)
  {
    for(int j=0;j<*dim;j++)
    {
      fscanf(pf, "%f", &M[i][j]);
    }
  }

  s = malloc(*dim*sizeof(float));
  if(s == NULL)
  {
    cleanup(M, s, v, *dim);
    exit(1);
  }
  for(int i=0;i<*dim;i++) fscanf(pf , "%f", &s[i]);

  v = malloc(*dim*sizeof(float));
  if(v == NULL) 
  {
    cleanup(M, s, v, *dim);
    exit(1);
  }
  for(int i=0;i<*dim;i++) v[i]=0;
 
  *x = v;
  *b = s;
  *A = M;
  fclose(pf);
}


void displayResult(float *x, int dim, float *b, float **A)
{
  printf("Dimension = %d\n", dim);

  printf("\nVoici la matrice A du problème.\n");
  for(int i=0;i<dim;i++)
  {
    for(int j=0;j<dim;j++)
    {
      printf("%g ", A[i][j]);
    }
    printf("\n");
  }
 
  printf("\nVoici le vecteur b.\n");
  for(int i=0;i<dim;i++) printf("b[%d] = %g \n", i, b[i]);

  printf("\nVoici le vecteur solution x.\n");
  for(int i=0;i<dim;i++) printf("x[%d] = %g \n", i, x[i]);
  
}

void gauss(float **A, float *b, float *x, int dim)
{
//// Triangularisation du vecteur
  for(int k=0;k<dim;k++)
  {
    for(int i=k+1;i<dim;i++)
    {
      for(int j=k+1;j<dim;j++)
        A[i][j] = A[i][j] - A[i][k] / A[k][k] * A[k][j];
      b[i] = b[i] - A[i][k]/A[k][k]*b[k];
      A[i][k] = 0;
    }
  }

//// Resolution de la vecteur
  for(int i=dim-1;i>=0;i--)
  {
    double stmp=0;
    for(int j=i-1;j<dim;j++)
    {
      stmp += (A[i][j]*x[j]);
    }

    x[i] = (b[i]-stmp)/A[i][i];
  }
}

void cleanup(float **A, float *b, float *x, int dim)
{
  if(b != NULL)
  {
    printf("Liberation de b.\n");
    free(b);
  }
  if(x != NULL) 
  {
    printf("Liberation de x.\n");
    free(x);
  }
  if(A != NULL)
  {
    for(int i=0;i<dim;i++)
    {
      if(A[i] != NULL) free(A[i]);
    }
    free(A);
  }
}
