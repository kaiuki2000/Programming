#include <stdio.h>
#include <math.h>

double pfrac,pint,res;


double Bernoulli (int n, double i){
  if(n==1)
    return(i);
  else{
    pfrac= modf(Bernoulli(n-1,i),&pint);
    res=2*pfrac*Bernoulli((n-1),i);
    return(res);}}

	       
int main(int argc, char **argv)
{
  int c=1;
  double i,value,pint,pfrac;
  FILE *fich;
  
  if(argc!=2){
    printf("\n***Erro no número de argumentos!***\nPor favor escreva o programa na forma:\n\n./Pratica1 <valor inicial>\n\n");
    printf("O programa vai terminar...\nClique no ENTER...");
    getchar();
    return(0);}

  fich= fopen("Bernoulli2.dat","wt");
  if(fich==NULL)
    {
      printf("***Erro na abertura do ficheiro***\nO programa vai terminar.\nClique no ENTER...");
      getchar();
      return(0);
    }
  
  sscanf(argv[1],"%lf",&i);
  printf("Número lido: %lf\n",i);

  for(c=1;c<=100;c++)
    {
      value= Bernoulli(c,i);
      printf("%3d:      %.10lf\n",c,value);
    }
  
  return(0);
}

      
  
