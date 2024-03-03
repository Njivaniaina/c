#include <stdio.h>
#include <math.h>

int main()
{ 
  double dx=0, x=0;
  float fx=0, x1;

  x = (sqrt(5)-1)/2;
  dx = (sqrt(5)-1)/2;
  fx = (sqrt(5)-1)/2;
  x1 = (sqrt(5)-1)/2;

  for(int i=0;i<49;i++)
  {
    dx *= x;
    fx *= x1;
  }
  printf("-Type double : x = %.20lf\n", dx);
  printf("-Type float  : x = %.20f\n", fx);

  return 0;
}
