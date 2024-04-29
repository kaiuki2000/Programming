#include <stdio.h>
#include <math.h>
int main ()
{
  float x0,x,r,x2;
  int i;
  FILE *br;
  i = 1;
  br= fopen("br.txt","wt");
  printf("Introduza o valor de x inicial e de r:");
  scanf("%f %f", &x0,&r);
  printf("r:%f\n",r);
  printf("x0:%f\n",x0);
  fprintf(br,"r:%f\n",r);
  fprintf(br,"x0:%f\n",x0);
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
	    fprintf(br,"%d: x=%f\n",i,x);
	    if (fabs(x2-x)<=0.0001)
	      {
		i=i-1000;
		printf("Cada órbita tem %d valores.\n",i);
		fprintf(br,"Cada órbita tem %d valores.\n",i);
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
  fclose(br);
  return 0;
}
