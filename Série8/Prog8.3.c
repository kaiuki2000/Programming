#include <stdio.h>



int combinacao(int n, int k) //Definição da função que calcula os elementos do triângulo de Pascal (combinações).
{
  if(k==0)
    return 1;
  return (combinacao(n,k-1)*(n+1-k))/k;
}



int main(int argc, char **argv)
{
  int n1,n2,N,t2,i,j,valor,comb;
  FILE *F1;
  char t;

  if (argc!=2) //Teste ao número de argumentos da função main.
    {
      printf("***Erro***\nEscreva o programa na forma:\n\n./Prog8.3 <N> em que N é o número de linhas do triângulo de Pascal\n");
      return(0);
    }

  if(sscanf(argv[1],"%d",&N)!=1) //Teste ao argumento introduzido: Este tem que ser um número inteiro.
    {
      printf("***Erro***\nEscreva o programa na forma:\n\n./Prog8.3 <N> em que N é o número de linhas do triângulo de Pascal\n");
      return(0);
    }
     
  if(N<=0) //Teste ao argumento introduzido: Este tem que ser um número inteiro positivo.
    {
      printf("***Erro***\nEscreva o programa na forma:\n\n./Prog8.3 <N> em que N é o número de linhas do triângulo de Pascal\n");
      return(0);
    }
  
  F1= fopen("Prog8.3.b","w+b"); //Abertura do canal de escrita/leitura (ficheiro do tipo binário).

  if(F1==NULL) //Teste à abertura do canal.
    {
      printf("***Erro na abertura do ficheiro***");
      fclose(F1);
      return(0);
    }
  

  for(n1=0;n1<N;++n1) //Ciclo que gera o triângulo de Pascal.
    {
      for(n2=n1+1;n2<N;++n2)
	printf(" ");
      for(n2=0;n2<=n1;++n2)
	{
	  comb=combinacao(n1,n2);
	  printf("%d ",comb);
	  if(fwrite(&comb,sizeof(int),1,F1)!=1) //Teste a fwrite. Escrita no ficheiro binário.
	    {
	      perror("fwrite");
	      return(0);
	    }
	}
      printf("\n");
    }

  
 
  while(1)
    {
      printf("\n\nDeseja ver algum elemento do triângulo?(s/n)\n"); //O programa pergunta se o utilizador deseja ler algum dos números escritos no ficheiro.
      
      while(1)
	{
	  scanf(" %c",&t); //Leitura do input introduzio.
	  if(t!='s'&&t!='n') //Testes ao input introduzido.
	    {
	      printf("\nO input introduzido não é válido!!\nEscreva 's' se desejar ver algum elemento ou 'n' em caso contrário\n");
	      while(getchar() != '\n') //Limpeza da 'fila de espera'.
		continue;
	    }
	  else
	    break;
	}
      
      if(t=='n') //O programa acaba se o utilizador não quiser ver nenhum elemento do triângulo.
	break;
  
      printf("\nQual o elemento que deseja ver? Escreva na forma <n k> em que n é a linha e k é o elemento da linha\n");//Caso o utilizador diga que sim (...).
      
      while(1)
	{
	  t2= scanf(" %d %d",&i,&j);
	  /* while(getchar() != '\n')
	     continue;*/
	  if((t2!=2)||(i<0)||(i>=N)||(j>i)||(j<0)) //Testes ao input introduzido (linhas). Aqui <i> é a linha e <j> é a coluna.
	    {
	      printf("\nO input introduzido não é válido!!\nEscreva na forma <n k> em que n é a linha e k é o elemento da linha (note que n terá que pertencer ao intervalo [0,%d] e k não poderá ser maior que n)\n",N-1);
	      while(getchar() != '\n') //Limpeza da 'fila de espera'.
		continue;
	      continue;
	    }
	  else
	    break;
	}
           
      
      if(fseek(F1,(((i*(i+1))/2)+j)*sizeof(int),SEEK_SET)) //Teste a fseek. Localização do número pedido pelo utilizador.
	{
	  perror("fseek");
	  return(0);
	}
      
      if(fread(&valor,sizeof(int),1,F1)!=1) //Teste a fread. Leitura do número.
	{
	  perror("fread");
	  return(0);
	}
      
      printf("O elemento lido foi: %d\n",valor); //Impressão do número lido.
    }

  
  
  fclose(F1); //Fecho do canal de escrita/leitura.
  return(0);
}
    
