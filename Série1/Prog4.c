#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
  //Declaração das variáveis.
  char wait;
  int num, i, n, t1,r;
  //É gerado um número aleatório entre 0 e 2000.
  srand (time(NULL));
  num = (((double)rand()/(double)RAND_MAX)*2000);
  //A variável de contagem é inicializada a 1.
  i=1;
  printf("Jogo da adivinha!\n\n");
  printf("Tente adivinhar qual o número que foi gerado ( nº inteiro não negativo inferior a 2000)\n");
  //Ciclo principal.
  while (1)
    {
      t1= scanf("%d",&n);
      //Ciclo de teste para a entrada introduzida.
      while (t1!=1)
	{
	  printf("A leitura é invalida\n");
	  printf("Introduza um novo número\n");
	  scanf("%c",&wait);
	  t1=scanf("%d",&n);
	}
      // Quando o nº introduzido é maior que o número gerado.
      if (n>num)
	{
	  printf("Está acima do número gerado. ");
	  if (fabs(n-num)<50)
	    {
	      printf("Está muito próximo!");
	    }
	  ++i;
	  printf("\n");
	  printf("\nTente novamente\n");
	}
      // Quando o nº introduzido é menor que o número gerado.
      if (n<num)
	{
	  printf("Está abaixo do número gerado. ");
	  if (fabs(n-num)<50)
	    {
	      printf("Está muito próximo!");
	    }
	  ++i;
	  printf("\n");
	  printf("\nTente novamente\n");
	}
      // Quando o nº introduzido é igual ao número gerado.
      if (n==num)
	{
	  printf("Parabens! Acertou no número em %d tentativas!\n",i);
	  // Pergunta se quer jogar novamente.
	  printf("Quer jogar outra vez? (1- sim; 2- não)\n");
	  scanf("%d",&r);
	  //Quebra o ciclo se disser que não e o programa acaba.
	  if (r==2)	      
	    break;
	  //O ciclo continua se disser que sim.
	  if (r==1)
	    {
	      //É gerado um novo nº aleatório.
	      num = (((double)rand()/(double)RAND_MAX)*2000);
	      printf("Tente adivinhar qual o número que foi gerado ( nº inteiro não negativo inferior a 2000)\n");
	      i=1;
	    }
	  
	}
    }
  return(0);
}
	  
	  
	  
  
