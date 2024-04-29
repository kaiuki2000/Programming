#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int nvezes (char *string1 , char *caracter)
{
  int contador, i;
  contador=0;
  
  for(i=0; i<strlen(string1); ++i)
    {
      if(string1[i] == caracter[0])
	{
	  contador += 1;
	}
    }
  return(contador);
}




int posicao (char *string1, char *caracter)
{
  int i;
  i=0;
  
  while(string1[i]!=caracter[0])
    {
      ++i;
      if(string1[i]==0)
	{
	  i=-2;
	  break;
	}
    }
  i+=1;
  return(i);
}
      



char* troca (char *string1, char *caracter1, char *caracter2)
{
  int i;

  for(i=0;i<strlen(string1);++i)
    {
      if(string1[i]==caracter1[0])
	{
	  string1[i]=caracter2[0];
	}
    }
  return (string1);
}











int main(int argc,char **argv)
{
  int c1,c2;
  char *trocado, *teste, *trocado2;
  
  c1= nvezes(argv[1],argv[2]);
  c2= posicao(argv[1],argv[2]);
  printf("\nO número de vezes que o caracter '%c' aparece na string '%s' é: %d\n",argv[2][0],argv[1],c1);
  if(c2<0)
    {
      printf("\nO caracter '%c' não surge na string '%s'\n",argv[2][0],argv[1]);
      return(0);
    }
  else
    {
      printf("\nA primeira ocorrência do caracter '%c' é na posição %d\n",argv[2][0],c2);
    }
  
  trocado= troca(argv[1],argv[2],argv[3]);
  printf("\nA nova string, após troca dos caracteres '%c' por '%c' é: '%s'\n",argv[2][0],argv[3][0],trocado);

  teste = (char*)malloc(strlen(argv[1]+1)*sizeof(char));
  strcpy(teste,argv[1]);
  trocado2= troca(teste,argv[2],argv[3]);
  printf("A nova string (teste), após troca dos caracteres '%c' por '%c' é: '%s'\n",argv[2][0],argv[3][0],trocado2);
  free(teste);
  return(0);
}
