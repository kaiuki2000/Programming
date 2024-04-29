#include <stdio.h>
#include <stdlib.h>

#define FNAME_DATA       "Prog9.1.txt"
#define GNUPLOT_COMMAND  "gnuplot Exec_Gnuplot"

int main (int argc, char **argv)
{
  
  double x0, v0, m, k, b, t0, t1, deltaT1, deltaT2, x, v, NUM=1e6, LAMBDA, OMEGA2;
  int i;
  FILE *F1;
  
  if(argc!=8)
    {
      printf("***Erro***\nO programa deve ser escrito na forma:\n\n./Prog9.1 <x0> <v0> <m> <k> <b> <t0> <t1>\n");
      return(0);
    }

  F1= fopen(FNAME_DATA,"wt");
    
  sscanf(argv[1],"%lf",&x0);
  sscanf(argv[2],"%lf",&v0);
  sscanf(argv[3],"%lf",&m);
  sscanf(argv[4],"%lf",&k);
  sscanf(argv[5],"%lf",&b);
  sscanf(argv[6],"%lf",&t0);
  sscanf(argv[7],"%lf",&t1);


  x=x0;
  v=v0;

  deltaT1= t1-t0;
  deltaT2=deltaT1/NUM;
  LAMBDA= b/(2*m);
  OMEGA2= k/m;

  //printf("%lf %lf\n",t0,x);
  fprintf(F1,"%lf %lf\n",t0,x);
	  
  for(i=1;i<NUM;i++)
    {
      v= v-(2*LAMBDA*v*deltaT2)-(OMEGA2*x*deltaT2);
      x=x+(v*deltaT2);
      // printf("%lf %lf\n",(t0+deltaT2*i),x);
      fprintf(F1,"%lf %lf\n",(t0+deltaT2*i),x);
    }

  system(GNUPLOT_COMMAND);
	 
  return(0);
}
  
