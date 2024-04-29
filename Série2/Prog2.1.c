#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definição da função bubble sort que vai ordenar os valores gerados por ordem crescente;
void Bubble_Sort (double *v, int N)
{
  double x;
  int ib,t;
  while (1)
    {
      t=0;
      // Algoritmo para trocar os valores;
      for(ib=0;ib<N-1;++ib)
	{
	  if(v[ib]>v[ib+1])
	    {
	      x= v[ib];
	      v[ib]=v[ib+1];
	      v[ib+1]=x;
	      t=1;
	    }
	}
      if (t==0)
	break;     
    }
}

int main(int argc, char **argv)
{
  double *v;
  int t1,t2,t3,i, N, Max, rep;
  //Abrir o ficheiro para escrever os valores.
  FILE *P2;
  char wait;
  P2 = fopen ("Prog2.1.txt","wt");
  if (argc!=3)
    {
      printf("O programa deve ser executado na forma:\n\n    ./Prog2.1 <N Max>\n\nEm que N é o nº de elementos e Max o valor máximo que podem assumir.\n");
      return (0);
    }
  t1= sscanf(argv[1],"%d",&N);
  t2= sscanf(argv[2],"%d",&Max);
  if (t1+t2!=2)
    {
      printf("A leitura dos valores é inválida.\n\nO programa deve ser executado na forma:\n\n    ./Prog2.1 <N Max>\n\nEm que N é o nº de elementos e Max o valor máximo que podem assumir.\n");
      return(0);
    }

  v= (double*) malloc(N*sizeof (double));
    
  srand(time(NULL));
  //Gerar valores aleatórios.
  for (i=0;i<N;i++)
    {
      v[i]=(((double)rand())/((double)RAND_MAX))*Max;
    }
  //Aplicação da função de ordenação(crescente) nos valores gerados.
  Bubble_Sort(v,N);
  for (i=0;i<N;++i)
    {
      printf("%d: %lf\n",i,v[i]);
      //Escrever no ficheiro .txt os valores gerados por ordem crescente.
      fprintf(P2,"%d: %lf\n",i,v[i]);
    }
  //Fecho do canal.
  fclose(P2);
  printf("Deseja repetir? (1- sim; 2-não)\n");
  t3=scanf("%d",&rep);

  while(rep!=1 && rep!=2)
    {
      
      while(t3!=1)
	{
	  printf("A leitura é invalida\n");
	  printf("(1- sim; 2-não)\n");
	  scanf("%c",&wait);
	  t3=scanf("%d",&rep);
	}
      printf("A leitura é invalida\n");
      printf("(1- sim; 2-não)\n");
      scanf("%c",&wait);
      t3=scanf("%d",&rep);
    }
  if(rep==2)
    return(0);
  while (1)
    {

    
     
      printf("Diga o número de valores que pretende e o valor máximo que podem assumir: <N Max>\n");
      t1= scanf("%d %d",&N,&Max);
      while(t1!=2)
	{
	  printf("A leitura é invalida\n");
	  printf("N e Max inteiros positivos <N Max>\n");
	  scanf("%c",&wait);
	  t1=scanf("%d %d",&N, &Max);
	}
     
	 
      P2 = fopen ("Prog2.1.txt","wt");

      v= (double*) realloc(v,N*sizeof (double));
    
      srand(time(NULL));
      //Gerar valores aleatórios.
      for (i=0;i<N;i++)
	{
	  v[i]=(((double)rand())/((double)RAND_MAX))*Max;
	}
      //Aplicação da função de ordenação(crescente) nos valores gerados.
      Bubble_Sort(v,N);
      for (i=0;i<N;++i)
	{
	  printf("%d: %lf\n",i,v[i]);
	  //Escrever no ficheiro .txt os valores gerados por ordem crescente.
	  fprintf(P2,"%d: %lf\n",i,v[i]);
	}
      //Fecho do canal.
      fclose(P2);
      printf("Deseja repetir? (1- sim; 2-não)\n");
      t3=scanf("%d",&rep);

      while(rep!=1 && rep!=2)
	{
      
	  while(t3!=1)
	    {
	      printf("A leitura é invalida\n");
	      printf("(1- sim; 2-não)\n");
	      scanf("%c",&wait);
	      t3=scanf("%d",&rep);
	    }
	  printf("A leitura é invalida\n");
	  printf("(1- sim; 2-não)\n");
	  scanf("%c",&wait);
	  t3=scanf("%d",&rep);
	}
      if(rep==2)
	return(0);



      
    }
  free(v);
  return (0);
}
