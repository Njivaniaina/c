#include <stdio.h>
#include <stdlib.h>

double **allocation(int line, int row);
void getData(double **x, int line, int row);
void print_matrice(double **x, int line, int row);
double *resolve(double **x, int line, int row);

int main()
{
  double **x = NULL;
  double *result = NULL;
  int line=0, row=0;
  
  printf("Entrer le nombre de ligne : ");
  scanf("%d", &line);
  printf("Entrer le nombre de colone : ");
  scanf("%d", &row);

  x = allocation(line, row);
  result = (double*)malloc(sizeof(double)*line);
 
  getData(x, line, row);
  print_matrice(x, line, row);
  result = resolve(x, line, row);
  print_matrice(x, line, row);

  printf("Les result sont : \n");
  for(int i=0;i<line;i++)
  {
    printf("r[%d] = %lf \n", i+1, result[i]);
  }

  return 0;
}

double **allocation(int line, int row)
{
  double **n=NULL;
  n = (double**)malloc(sizeof(double*)*line)  ;
  for(int i=0;i<line;i++)
  {
    n[i] = (double*)malloc(sizeof(double)*row);
  }
  return n;
}

void getData(double **x, int line, int row)
{
  for(int i=0;i<line;i++)
  {
    printf("Entrer successivement les valeurs de la %d eme ligne : ", i+1);
    for(int j=0;j<row;j++)
    {
      scanf("%lf", &x[i][j]);
    }
  } 
}

double *resolve(double **x, int line, int row)
{
  double *result = NULL;
  
  result = (double*)malloc(sizeof(double)*line);

  for(int i=0;i<line-1;i++)
  {
    double a = 0;
    for(int k=i+1;k<line;k++)
    {
      a = x[k][i]/x[i][i];
      //printf("a = %lf / %lf =  %lf\n", x[k][i], x[i][i],  a);
      for(int j=i;j<row;j++)
      { 
        x[k][j] = x[k][j] - x[i][j]*a;
      }
    }
  }

  for(int i=line-1;i>=0;i--)
  {
    double stmp=0;

    printf("Le nombre i = %d\n", i);
    for(int j=row-1;j>i+1;j--)
    {
      stmp += (x[i][j-1]*result[j-1]);
      printf("%lf = (%lf*%lf)\n", stmp, x[i][j-1] , result[j-1]);
    }

    result[i] = (x[i][row-1]-stmp)/x[i][i];
    printf("Les resultat: (%lf-%lf)/%lf = %lf (r[%d])\n\n", x[i][row-1], stmp, x[i][i], result[i], i+1);
  }

  return result;
}

void print_matrice(double **x, int line, int row)
{
  printf("\nLe matrice est : \n");
  for(int i=0;i<line;i++)
  {
    for(int j=0;j<row;j++)
    {
      printf("%lf ", x[i][j]);
    }
    puts("");
  }
  printf("\n");
}
