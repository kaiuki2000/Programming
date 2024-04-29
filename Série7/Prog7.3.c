
/****************************
 *                          *
 *    Serie 7 Programa 3    *
 *      Realizado por:      *
 *      Afonso e Nuno       *
 *                          *
 ****************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int  main(int argc, char **argv)
{
  int N,*v,i=0,teste,j=0,u=0,t2;
  char t;
  FILE *T1;


  //Testes relativos aos argumentos introduzidos no terminal.
  if(argc!= 2)
    {
      printf("\n***Erro***\nEscreva o programa na forma ./Prog7.3 <N>\n\n");
      return(0);
    }

  if(sscanf(argv[1],"%d",&N)!=1)
    {
      printf("\n***Erro***\nLeitura inválida. <N> deve ser um inteiro positivo\n\n");
      return(0);
    }

  if(N<=0)
    {
      printf("\n***Erro***\nLeitura inválida. <N> deve ser um inteiro positivo\n\n");
      return(0);
    }



  

  //Abertura do ficheiro de leitura/escrita binária (canal de leitura/escrita).
  T1= fopen("Prog7.3.b","w+b");

  //Caso a abertura falhe, terminar o programa.
  if(T1 == NULL)
    {
      perror("Erro na abertura do(s) ficheiro(s)");
      fclose(T1);
      return(0);
    }


  
  //Alocação do espaço necessário para o vetor que nos permitirá obter os números primos.
  v=(int*) malloc ((N+1)*sizeof(int));



  //Inicializar o vetor com todos os elementos iguais a 1.
  for(i=0;i<N+1;i++)
    {
      v[i]=1;
    }

  //Definição do valor máximo até ao qual vamos aplicar o método do 'Crivo de Eratóstenes'.
  teste= (int)sqrt(N);

  //Aplicação do método para identificar os números primos.
  for(i=2;i<=teste;i++)
    {
      for(j=4;j<N+1;j++)
	{
	  if((v[j]!=0) && (j%i==0))
	    v[j]=0;
	}
    }

  j=0;

  //Impressão dos resultados no ecrã/ficheiro binário.
  for(i=2;i<N+1;i++)
    {
      if(v[i]==1)
	{
	  printf("%10d ",i);
	  fwrite(&i,sizeof(int),1,T1);
	  j++;
	  
	  if(j%6==0) //Impressão em colunas de 6 elementos.
	    {
	      printf("\n");
	    }
	  
	}
    }



  //Ciclo para ler número do ficheiro binário e apresentá-los no ecrã.
  while(1)
    {
      printf("\n\nDeseja ver algum numero primo?(s/n)\n");
      
      while(1)
	{
	  scanf(" %c",&t);
	  if(t!='s'&&t!='n') //Testes ao input introduzido.
	    {
	      printf("\nO input introduzido não é válido!!\nEscreva 's' se desejar ver algum número ou 'n' em caso contrário\n");
	      continue;
	    }
	  else
	    break;
	}
      
      if(t=='n') //O programa acaba se o utilizador não quiser ver nenhum número primo.
	break;
  
      printf("\nQue número primo quer encontrar? (2 é o primeiro)\n"); //Caso o utilizador diga que sim (...).
      
      while(1)
	{
	  t2= scanf(" %d",&u);
	  if((t2!=1)||(u>j)||(u<=0)) //Testes ao input introduzido.
	    {
	      printf("\nO input introduzido não é válido!! (Foram gerados %d números primos)\nEscreva, por favor, um número entre 1 e %d\n",j,j);
	      while(getchar() != '\n')
		continue;
	      continue;
	    }
	  else
	    break;
	}
      
      fseek(T1,(u-1)*sizeof(int),SEEK_SET); //Localização do número pedido pelo utilizador.
      fread(&u,sizeof(int),1,T1); //Leitura deste número.
      
      printf("O número primo lido foi: %d\n",u); //Impressão do número lido.
    }
    


  //Fecho do canal de escrita/leitura e libertação da variável v (free(v)).
      fclose(T1);
      free(v);
      
      return(0);
}
  
