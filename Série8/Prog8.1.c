#include <stdio.h>

int main (int argc, char **argv)
{
  
  double k,x0,ti,tf,deltaT1,deltaT2,x,NUM=1e3;
  int i;
  FILE *F1;
  
  if(argc!=5)
    {
      printf("***Erro***\nO programa deve ser escrito na forma:\n\n./Prog8.1 <K> <x0> <ti> <tf>\n");
      return(0);
    }

  F1= fopen("Prog8.1.txt","wt");
    
  sscanf(argv[1],"%lf",&k);
  sscanf(argv[2],"%lf",&x0);
  sscanf(argv[3],"%lf",&ti);
  sscanf(argv[4],"%lf",&tf);

  x=x0;

  deltaT1= tf-ti;
  deltaT2=deltaT1/NUM;

  printf("%lf %lf\n",ti,x);
  fprintf(F1,"%lf %lf\n",ti,x);
	  
  for(i=1;i<NUM;i++)
    {
      x=x*(1-k*deltaT2);
      printf("%lf %lf\n",(ti+deltaT2*i),x);
      fprintf(F1,"%lf %lf\n",(ti+deltaT2*i),x);
    }
  
  return(0);
}
  

  
