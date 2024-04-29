#include <stdio.h>
#include <math.h>
int main ()
{
  float x0,x,r,x2;
  int i;
  i = 1;
  printf("Introduza o valor de x inicial e de r:");
  scanf("%f %f", &x0,&r);
  if ((0<=x0 && x0<=1)&&(0<=r && r<=4))
    {
      while (i<=1064)
	if (i<=1000)
	  {
	    x=r*x0*(1-x0);
	    x0=x;
	    ++i;
	    x2=x;
	  }
	else
	  {
	    x=r*x0*(1-x0);
	    printf("%d: x=%f\n",i,x);
	    if (fabs(x2-x)<=0.0001)
	      {
	      i=i-1000;
		printf("Cada órbita tem %d valores.\n",i);
	      break;
	      }
	    x0=x;

	    ++i;
	  }
    }
  else
    {
      printf("Os valores não estão corretos '0<x0<1' e '0<r<4'\n");
    }
  return 0;
}
