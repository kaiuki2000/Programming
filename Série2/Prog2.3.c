#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
  
  //Declaração das variáveis;
  int s1len,s2len;
  char *s1, *s2;

  //Testes para os argumentos introduzidos.
  if (argc!=3)
    {
      printf("***Erro***\n\n O programa deve ser escrito na forma:\n\n ./Prog2.3 <string1> <string2>\n\n");
      return(0);
    }
  
  //Obtenção do comprimento das strings argv[1] e argv[2].
  s1len= strlen(argv[1]);
  s2len= strlen(argv[2]);

  //Impressão dos comprimentos das strings.
  printf("\nO primeiro string introduzido foi: '%s' e o seu comprimento é: %d.\n",argv[1],s1len);
  printf("O segundo string introduzido foi: '%s' e o seu comprimento é: %d.\n\n",argv[2],s2len);

  //Atribuição da memória necessária para a string resultante da junção das strings argv[1] e argv[2].
  s1 = (char*)malloc((s1len+s2len+1)*sizeof(char));

  //Copiar a string argv[1] para a string s1 e posterior junção da string s1 com a a string argv[2].
  strcpy(s1,argv[1]);
  strcat(s1, argv[2]);

  //Impressão da string resultante s1.
  printf("A string resultante da junção da 1ª string com a 2ª é: %s (1).\n", s1);

  //Atribuição da memória necessária para a string resultante da junção das strings argv[2] e argv[1].
  s2= (char*)malloc((s1len+s2len+1)*sizeof(char));

  //Copiar a string argv[2] para a string s2 e posterior junção da string s2 com a a string argv[1].
  strcpy(s2,argv[2]);
  strcat(s2,argv[1]);

  //Impressão da string resultante s2.
  printf("A string resultante da junção da 2ª string com a 1ª é: %s (2).\n\n", s2);

  //Comparação das strings s1 e s2 através da função strcmp.
  if (strcmp(s1,s2)==0)
    {
      printf("As strings são iguais.\n\n");
      return (0);
    }
  if (strcmp(s1,s2)<0)
    {
      printf("A string (2) é maior que a string (1).\n\n");
      return (0);
    }
   if (strcmp(s1,s2)>0)
    {
      printf("A string (1) é maior que a string (2).\n\n");
      return (0);
    }
   free (s1);
   free (s2);
  return (0);
}

 
