#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
  double real;
  double imag;
  double norma;
}Complexo;

void ordenar(Complexo **comp,int N)
{
  int i=0,t=0;
  Complexo *troca;

  while(1)
    {
      t=0;
      for(i=0;i<N-1;i++)
	{
	  if(comp[i]->norma < comp[i+1]->norma)
	    {
	      troca=comp[i];
	      comp[i]=comp[i+1];
	      comp[i+1]=troca;
	      t=1;
	    }
	}
      if(t==0)
	break;
    }
}


void trocar(Complexo **comp, int a, int b)
{
  Complexo *troca;

  troca=comp[a];
  comp[a]=comp[b];
  comp[b]=troca;
}

int main(int argc, char **argv)
{
  int N=0,i=0,a,b;
  Complexo **comp;
  char teste;
  
  if(argc!= 2)
    {
      printf("***Erro***\nEscreva o programa na forma ./Prog7.1 <N>\n\n");
      return(0);
    }

  if(sscanf(argv[1],"%d",&N)!=1)
    {
      printf("***Erro***\nLeitura inválida. <N> deve ser um inteiro positivo");
      return(0);
    }

  if(N<=0)
    {
      printf("***Erro***\nLeitura inválida. <N> deve ser um inteiro positivo");
      return(0);
    }

  srand(time(NULL));
  
  comp= (Complexo**)malloc(N*sizeof(Complexo*));
  for(i=0;i<N;i++)
    comp[i]=(Complexo*)malloc(sizeof(Complexo));

  for(i=0;i<N;i++)
    {
      comp[i]->real= ((double)rand()/(double)RAND_MAX)*24-8;
      comp[i]->imag= ((double)rand()/(double)RAND_MAX)*24-8;
      comp[i]->norma= sqrt(pow(comp[i]->real,2)+pow(comp[i]->imag,2));
    }

  printf("Complexos gerados:\n\n");
  
  for(i=0;i<N;i++)
    {
      printf("%lf+%lfi |%lf+%lfi|=%lf\n\n",comp[i]->real,comp[i]->imag,comp[i]->real,comp[i]->imag,comp[i]->norma);
    }

  ordenar(comp,N);

  printf("\nComplexos ordenados de forma decrescente pela norma:\n\n");
  
  for(i=0;i<N;i++)
    {
      printf("%lf+%lfi |%lf+%lfi|=%lf\n\n",comp[i]->real,comp[i]->imag,comp[i]->real,comp[i]->imag,comp[i]->norma);
    }

  while(1)
    {
      printf("\n\nDeseja trocar algum dos complexos?\n\n");
      printf("(a)-sim; (b)-não.\n");
      scanf(" %c",&teste);
      
      if(teste=='b') //Caso teste != b (...) (acabar)
	break;

      printf("\nQuais complexos deseja trocar? Escreva na forma a,b (com a e b entre 0 e %d-1)\n",N);
      scanf(" %d,%d",&a,&b);

      trocar(comp,a,b);

      printf("\nComplexos reordenados:\n\n");
      
      for(i=0;i<N;i++)
	{
	  printf("%lf+%lfi |%lf+%lfi|=%lf\n\n",comp[i]->real,comp[i]->imag,comp[i]->real,comp[i]->imag,comp[i]->norma);
	}
      
    }
	
  free(comp); 
  return(0);
}
      
  
  
      
