#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


int main (int argc, char**argv)
{
  int p2[16], i, n, p;
  char r[17];
  unsigned short int u=0;

  p2[0]=1;

  //Calculo das potencias de base 2

  for(i=1; i<16; ++i)
    {
      p2[i]=2*p2[i-1];

    }

  //Gerar valor que mais tarde passamos a binario

  srand(time(NULL));

  for(i=0; i<16; ++i)
    {
      if((rand()%2)==1)
	{
	  u= u| p2[i];

	}
    }

  //Passar o valor gerado a binario e coloca-lo num vetor de strings

  for(i=0; i<16; ++i)
    {
      if((u & p2[i])==0)
	{
	  r[i]=48;
	}
      else r[i]=49;
    }
  r[i]=0;

  i=0;

  //Impressao do vetor de strings
    
  printf("%s\n", r);

  //Ciclo para a repeticao do programa

  while(1)
    {

      printf("Qual o spin que pretende mudar de sinal? (0-15) ");

      if((scanf("%d", &n)!=1))
	{
	  printf("Erro na leitura do spin que quer mudar\n");
	  return -1;
	}
	  
      if (n<0 || n>15)
	{
	  printf("O número está fora do intervalo pretendido!\n");
	  return -1;
	}


      //Troca do spin pedido pelo utilizador

      u= u ^ p2[n];

      for(i=0; i<16; ++i)
	{
	  if((u & p2[i])==0)
	    {
	      r[i]=48;
	    }
	  else r[i]=49;
	}

      printf("%s\n", r);

      printf("Quer voltar a trocar um spin? (1- Sim  0-Nao) ");
      
      if((scanf("%d", &p)!=1))
	{
	  printf("Erro na percecao se quer voltar a correr o programa\n");
	  return -1;
	}
	  

      //Paragem do programa se o utilizador nao quiser repetir

      if(p!=1)
	break;
    }
}
