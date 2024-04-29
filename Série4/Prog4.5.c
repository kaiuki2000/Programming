
#include <stdio.h>
#include <stdlib.h>


// Erro no Input
void help ()
{
  printf ("\n\nPara utilizar este programa, dê duas strings quando o evoca.\nDeste modo: ./8Prog04_01 'String1' 'String2'");
  printf ("\n---------------------------------------------------------------------------------------------------x---------------------------------------------------------------------------------------------------\n\n");
  exit (1);
}


// Strlen
int str_len (const char *s)
{
  int i = 0;         //Contador

  for (i=0; s[i]!=0; i++);

  return i;
  /*Nós sabemos que o valor de i corresponde à posição um caracter que já não pertence à string que seria impressa, contudo como str[0] corresponde ao primeiro caracter da string, achámos próprio
    retornar i, uma vez que este vai ser o número total de caracteres                                                                                                                              */
} 


// Strcpy
char *str_cpy(char *str1, const char *str2)
{
  int i = 0;         //Contador

  for (i=0; str2[i]!=0; i++)
    str1[i] = str2[i];

  str1[i] = 0;
  
  return str1;
}


// Strcat
char *str_cat1(char *str1, const char *str2)
{
  int i = 0;         //Contador Utilizado no Cálculo da dimensão da str1
  int t = 0;         //Contador Utilizado na Cópia da str2 para a str1

  for (i=0; str1[i]!=0; i++);

  for (t=0; str2[t]!=0; t++)
    str1[t+i] = str2[t];

  str1[t+i] = 0;

  return str1;
}


// Strcat Utilizando Str_len e Str_cpy (definidos no programa)
char *str_cat2(char *str1, const char *str2)
{
  int l = 0;         //Comprimento de str1
  
  l = str_len(str1);
  
  str_cpy (&str1[l], str2);

  str1[l + str_len (str2)] = 0;

  return str1;
}


// Main
int main (int argc, char **argv)
{
  // Declaração das Variáveis
   int  i = 0;         //Contador
   int  l = 0;         //Comprimento de argv[i]
  char *S    ;         //String para a qual a qual são copiados e adicionados os argumentos


  // Nome e Autores do Programa
  printf ("\n---------------------------------------------------------------------------------------------------x---------------------------------------------------------------------------------------------------");

  printf  ("\nFunções de Strings");

  printf ("\n\nAutores:\nBruno Oliveira | Ist193367\nDavid Ferreira | Ist193371");

  
  // Teste dos Argumentos
  if (argc!=3)
    help ();

  // a)
  printf ("\n\na) Aplicação da função análoga a strlen que criámos a todos os argumentos dados:");
    
  for (i=1; i<3; i++)
    {
      l = str_len(argv[i]);
     
      printf ("\n   -A string '%s' tem %d caracteres.", argv[i], l);
    }


  // Alocação de Memória para S
  S = (char*) malloc ((str_len (argv[1]) + str_len(argv[2]) + 1) * sizeof (char));
  /* sizeof (char) = 1 byte */

  
  // b)
  printf ("\n\nb) Aplicação da função análoga a strcpy que criámos para copiar o primeiro argumento dado para outra string:");

  str_cpy (S, argv[1]);
  
  printf ("\n   -Resultado da cópia de '%s' para uma nova string: '%s'", argv[1], S);

  
  // c)
  printf ("\n\nc) Aplicação da primeira função análoga a strcat que criámos para juntar o segundo argumento à cópia que fizemos do primeiro na alínea anterior:");
  
  printf ("\n   -Resultado da junção de '%s' a '%s': ", argv[2], S);

  str_cat1 (S, argv[2]);

  printf ("'%s'", S);
    
  
  // d)
  /*Apesar de não ser pedido no enunciado, decidimos aplicar a segunda versão da função strcat que criámos (str_cat2) com a intenção de a testar.
    Para tal, voltámos a utilizar a função str_cpy para copiar o primeiro argumento dado para o vetor S e utilizamos a função str_cat2 para juntar o segundo argumento ao vetor S.*/

  str_cpy (S, argv[1]);

  printf ("\n\nd) Aplicação da seguunda função análoga a strcat que criámos para juntar o segundo argumento à cópia que fizemos do primeiro:");
  
  printf ("\n   -Resultado da junção de '%s' a '%s': ", argv[2], S);
  
  str_cat2 (S, argv[2]);
  
  printf ("'%s'", S);
  
  
  // Finalizar Programa
  free (S);
  
  printf ("\n---------------------------------------------------------------------------------------------------x---------------------------------------------------------------------------------------------------\n\n");
  
  return (0);
}
