#include <stdio.h>
#include <stdlib.h>

double calcule(double *a, int power, double x);
double *getData(int *power, double *x);

int main()
{
  double *a=NULL, x=0, result=0;
  int power=0;

  a = getData(&power, &x);
  result = calcule( a, power, x);

  printf("Le resultat est : %lf\n", result);

  return 0;
}

double *getData(int *power, double *x)
{
  double *a;
  printf("Entrer le puissance maximum : ");
  scanf("%d", power);
  a = (double*)malloc(sizeof(double)*((*power)+1));
  printf("Entrer succesivement les a[n] : ");
  for(int i=0;i<*power+1;i++)
  {
    scanf("%lf", &a[i]);
  }
  printf("Enter la valeur de x : ");
  scanf("%lf", x);
  return a;
}

double calcule(double *a, int power, double x)
{
  double result = 1;
  for(int i=0;i<power;i++)
  {
    result = (result*a[i]) + a[i+1];
  }
  return result;
}
