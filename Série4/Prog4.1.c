#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
  
  int i;
  double parteint, partef,x;
  FILE *fich;

  sscanf(argv[1],"%lf",&x);


  fich= fopen("Bernoulli.dat","wt");
  for(i=0;i<100;i++)
    {
      partef=  modf(x, &parteint);
      x=2*x*partef;
      printf("%d:      %.10lf\n", i, x);
      fprintf(fich,"%d:      %.10lf\n", i, x);
    }
  fclose(fich);
  return(0);
}
      
      
  
  
  
  
  
  
