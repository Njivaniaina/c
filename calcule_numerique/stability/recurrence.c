#include <math.h>
#include <stdio.h>

int main()
{
  float x=0, f0=1, f1=1, f2=1;

  f0 = (sqrt(5)-1)/2;
  f1 = f0;
  f2 = f1 * f0;

  for(int i=0;i<48;i++)
  {
    x = f1 - f2;
    f1 = f2;
    f2 = x;
  }
  

  printf("x = %.20lf\n", x);

  return 0;
}
