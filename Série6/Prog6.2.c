#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
  FILE *F1, *F2;
  char *linha;
  int i, comp;
  i=0;


  
  //Teste do número de argumentos introduzidos no terminal.
  if(argc!=3)
    {
      printf("\n***Erro***\nEscreva o programa do seguinte modo:\n");
      printf("./Prog6.2 ficheiro_de_leitura.txt ficheiro_de_escrita.txt \n\n");
      return (0);
    }

  
  
  //Abertura dos canais de leitura/escrita.
  F1 = fopen(argv[1] , "rt");
  F2 = fopen(argv[2] , "wt");

  
  
  //Testes para averiguar se a abertura dos canais foi bem sucedida.
  if(F1 == NULL)
    {
      perror("Erro na abertura do(s) ficheiro(s)");
      return(0);
    }


  if(F2 == NULL)
    {
      perror("Erro na abertura do(s) ficheiro(s)");
      return(0);
    }


  
  //Alocação do espaço para a string utilizada pelo programa na inversão do texto das linhas.
  linha= (char*)malloc(1024*(sizeof(char)));


  
  //Ciclo que faz a leitura das linhas de F1 e escreve-as, invertidas, em F2.
  while(1)
    {
      if(fgets(linha,1025,F1) == NULL)
	break;
      
      comp= strlen(linha);

      if((linha[comp-1]==10)&&(linha[comp-2]==13))
	{
	  for(i=comp-3;i>=0;i--)
	    fprintf(F2,"%c",linha[i]);
	  for(i=comp-2;i<comp;i++)
	    fprintf(F2,"%c",linha[i]);
	}
      
      if((linha[comp-1]==10)&&(linha[comp-2]!=13))
	{
	  for(i=comp-2;i>=0;i--)
	    fprintf(F2,"%c",linha[i]);
	  for(i=comp-1;i<comp;i++)
	    fprintf(F2,"%c",linha[i]);
	}
	  
      if ((linha[comp-1]!=10)&&(linha[comp-2]!=13))
	{
	  for(i=comp-1;i>=0;i--)
	    fprintf(F2,"%c",linha[i]);
	}
    }


  
  //Fecho dos canais de leitura/escrita.
  fclose(F1);
  fclose(F2);


  
  //Libertação da memória da string 'linha'.
  free(linha);

  return(0);
}
