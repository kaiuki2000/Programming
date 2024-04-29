#include <stdio.h>
#include <stdlib.h>





void ordenar(double *r, int tamanho) //Bubble Sort
{
  int i=0;
  int t=0;
  double intermedio;
  
  while(1)
    {
      t=0;
      for(i=0;i<tamanho-1;i++)
	{
	  if(r[i]>r[i+1])
	    {
	      intermedio= r[i];
	      r[i]= r[i+1];
	      r[i+1]= intermedio;
	      t=1;
	    }
	}
      if(t==0)
	break;
    }
}


  


int eliminaRepetidos(double *r, int tamanho)
{
  int i=0;
  int c=0;
  int c1;
  
  for(i=0;i<tamanho-1;i++)
    {
      if(r[i]!=r[i+1])
	{
	  r[c]=r[i];
	  c++;
	}
    }
  
  r[c]=r[tamanho-1];
  c1=c;
  
  while(c1<tamanho-1)
    {
      r[c1+1]=0;
      c1++;
    }
  
  r= (double*) realloc (r, (c+1)*sizeof (double));
  return(c);
}




  
int main (int argc, char **argv)
{
  int N,M,p,q,c,z,tamanho;
  double *r;
  FILE *fich;
  
  if(argc !=3)
    {
      printf("Input inválido!! O programa deve ser iniciado da seguinte forma:\n\n ./Prog5.2 <N> <M> com N e M números inteiros positivos.\n\n");
      return(0);
    }

  if((sscanf(argv[1],"%d",&N)+sscanf(argv[2],"%d",&M))!=2)
    {
      printf("Input inválido!! N e M devem ser números inteiros positivos.\n");
      return(0);
    }

  fich=fopen("Prog5.2.txt","wt");

  tamanho=N*M;
  c=0;
  r= (double*) malloc (tamanho*sizeof (double));
  
  for(p=1;p<=N;p++)
    {    
      for(q=1;q<=M;q++)
	{
	  r[c]=(double)p/(double)q;
	  c++;
	}    
    }

  printf("\nValores gerados:\n\n");
  fprintf(fich,"\nValores gerados:\n\n");
  
  for(z=0;z<=tamanho-1;z++)
    {
      printf("%d: %lf\n",z+1,r[z]);
      fprintf(fich,"%d: %lf\n",z+1,r[z]);
    }

  ordenar(r,tamanho);
  printf("\n");
  fprintf(fich,"\n");

  printf("\nValores ordenados:\n\n");
  fprintf(fich,"\nValores ordenados:\n\n");
  
  for(z=0;z<=tamanho-1;z++)
    {
      printf("%d: %lf\n",z+1,r[z]);
      fprintf(fich,"%d: %lf\n",z+1,r[z]);
    }

  c= eliminaRepetidos(r,tamanho);
  
  printf("\n");
  fprintf(fich,"\n");

  printf("\nValores ordenados sem repetição:\n\n");
  fprintf(fich,"\nValores ordenados sem repetição:\n\n");
  
  for(z=0;z<=c;z++)
    {
      printf("%d: %lf\n",z+1,r[z]);
      fprintf(fich,"%d: %lf\n",z+1,r[z]);
    }

  printf("\n");
  fprintf(fich,"\n");
  
  free(r);
  return (0);
}


