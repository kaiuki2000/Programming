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
      for(ib=0;ib<N;ib++)
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

int main()
{
  double N, Max, v[10000];
  int t1,t2,i;
  //Abrir o ficheiro para escrever os valores.
  FILE *P2;
  P2 = fopen ("Prog2.txt","wt");
    
  srand(time(NULL));
  printf("Quantos números reais aleatórios pretende ordenar? (tem que ser menor que 10000!)\n");
  t1= scanf("%lf",&N);
  //Testes de leitura.
  if (t1!=1)
    {
      printf("Leitura incorreta (Teste=%d)\n",t1);
      return(0);
    }
  if (N>=10000)
    {
      printf("O número tem que ser menor que 10000\n");
      return (0);
    }
  if (N<1)
    {
      printf("O número tem que ser maior que 0\n");
      return (0);
    }
  printf("Qual o valor máximo que os números podem tomar?\n");
  t2= scanf("%lf",&Max);
  //Outro teste.
  if(t2!=1)
    {
      printf("Leitura incorreta (Teste=%d)\n",t2);
      return (0);
    }
  //Gerar valores aleatórios.
  for (i=0;i<N;i++)
    {
      v[i]=(((double)rand())/((double)RAND_MAX))*Max;
}
  //Aplicação da função de ordenação(crescente) nos valores gerados.
Bubble_Sort(v,N);
for (i=0;i<N;i++)
  {
  printf("%d: %lf\n",i,v[i]);
  //Escrever no ficheiro .txt os valores gerados por ordem crescente.
fprintf(P2,"%d: %lf\n",i,v[i]);
  }
//Fecho do canal.
fclose(P2);
return (0);
}


  
