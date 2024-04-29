#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
  
{
  
  int N, Num, i, v[100], min, max, pos, neg, par, impar;
  double N2;
  FILE *fich;

  
  //Testes para o argumento introduzido. O programa deve fechar se o argumento não for um número ou se o número introduzido for negativo.
  if (argc!= 2)
    {
      printf("A leitura não é válida.\n\nEscreva o programa na forma ./Prog3.4 <Número de números aleatórios a gerar (inteiro positivo)>\n");
      return (0);
    }
  
  if (sscanf(argv[1],"%d",&N)!=1)
    {
      printf("A leitura não é válida.\n\nEscreva o programa na forma ./Prog3.4 <Número de números aleatórios a gerar (inteiro positivo)>\n");
      return (0);
    }
  
  if (N<0)
    {
      printf("A leitura não é válida.\n\nEscreva o programa na forma ./Prog3.4 <Número de números aleatórios a gerar (inteiro positivo)>\n");
      return (0);
    }

  //Teste para verificar se o número introduzido é inteiro. O programa deve fechar caso o número introduzido não seja inteiro.
  sscanf(argv[1],"%lf",&N2);
  if (N2!=N)
    {
      printf("A leitura não é válida.\n\nEscreva o programa na forma ./Prog3.4 <Número de números aleatórios a gerar (inteiro positivo)>\n");
      return(0);
    }

  
  //Abertura do ficheiro, após os testes.
  fich=fopen("Prog3.4.txt","wt");

  
  //Declaração da função srand para depois podermos gerar números aleatórios.
  srand(time(NULL));

  
  //Declaração dos valores máximo e mínimo que os números podem tomar.
  min=80;
  max=-21;

  
  //Declaração das varíaveis de contagem para o nº de números positivos e negativos.
  pos=0;
  neg=0;

  
  //Declaração das varíaveis de contagem para o nº de números pares e ímpares.
  par=0;
  impar=0;

  
  //Ciclo para zerar o vetor.
  for(i=0;i<100;++i)
    {
      v[i]=0;
    }

  
  //Ciclo que gera os 'N' números aleatórios e faz a contagem de quantas vezes cada nº saiu, o maior e o menor nº que saíram, quantos nºs positivos e negativos saíram e, por fim, quantos nºs pares e ímpares saíram.
  for(i=0;i<N;++i)
    {
      Num = ((double)rand())/((double)RAND_MAX)*101-21; /* Para obtermos o intervalo [-20,79] tivemos que multiplicar por 101 e subtrair 21. Isso daria o intervalo [-21,80] (teórico). No entanto, na pr-
                                                           ática, verifica-se que apenas saem números no intrvalo [-20,79], como pretendido. */
      
      v[Num+20]++;
      
      if(Num<min)
	min=Num;
      
      if(Num>max)
	max=Num;
      
      if(Num<0)
	neg+=1;
      
      if(Num>=0)
	pos+=1;

      if((Num%2)==0)
	par+=1;

      if((Num%2)!=0)
	impar+=1;
    }

  
  //Ciclo que imprime quantas vezes saiu cada nº.
  printf("\nNúmeros que saíram:\n\n");
  for(i=0;i<100;++i)
    {
      if(v[i]!=0)
      printf("%3d: %d vezes.\n", i-20, v[i]);
    }

  
  //Impressão do resto dos resultados obtidos com o ciclo acima (no terminal).
  printf("\nO maior número gerado foi %d e o menor foi %d.\n", max, min);
  printf("Foram gerado(s) %d números positivos e %d números negativos.\n", pos, neg);
  printf("Foram gerado(s) %d números pares e %d números ímpares.\n", par, impar);

  
  //Impressão dos resultados obtidos com o ciclo acima (no ficheiro).
  fprintf(fich,"Foram gerados %d números.\n", N);
  fprintf(fich,"O maior número gerado foi %d e o menor foi %d.\n", max, min);
  fprintf(fich,"Foram gerado(s) %d números positivos e %d números negativos.\n", pos, neg);
  fprintf(fich,"Foram gerado(s) %d números pares e %d números ímpares.\n\nNúmeros que saíram:\n\n", par, impar);

  
  //Ciclo que imprime quantas vezes saiu cada nº (no ficheiro).
  for(i=0;i<100;++i)
    {
      if(v[i]!=0)
	fprintf(fich,"%3d: %d vezes.\n", i-20, v[i]);
    }

  
  //Fecho do ficheiro.
  fclose(fich);

  
  return (0);
}
