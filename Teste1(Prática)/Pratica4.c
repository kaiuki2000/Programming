#include <stdio.h>
#include <stdlib.h>


int Mystrlen (char *s)
{
  int len=0;
  while(s[len]!=0)
    {
      len++;
    }
  return(len);
}


char* Mystrcpy (char *s1, char *s2)
{
  int i=0;
  while(s2[i]!=0)
    {
      s1[i]=s2[i];
      i++;
    }
  return(s1);
}


char* Mystrcat (char *s1, char *s2)
{
  int i=0,l;
  l=Mystrlen(s1);
  while(s2[i]!=0)
    {
      s1[l+i]=s2[i];
      i++;
    }
  return(s1);
}

  
int main(int argc, char **argv)
{

  char *s1,*s2,*s3;
  int l1,l2,l3;
  
  if(argc!=3)
    {
      printf("***Erro***\nO input introduzido não é válido.\n");
      return(0);
    }

  l1= Mystrlen(argv[1]);
  l2= Mystrlen(argv[2]);

  printf("Os comprimentos das strings são, respetivamente: %d e %d\n\n",l1,l2);

  s1= (char*) malloc ((l1+1)*sizeof(char));
  s2= (char*) malloc ((l2+1)*sizeof(char));

  s1= Mystrcpy(s1,argv[1]);
  s2= Mystrcpy(s2,argv[2]);

  printf("Resultado da cópia da string1 para uma string auxiliar 's1': %s\n",s1);
  printf("Resultado da cópia da string2 para uma string auxiliar 's2': %s\n",s2);

  s3= (char*) malloc ((l1+l2+1)*sizeof(char));
  s3= Mystrcpy(s3,s1);
  s3= Mystrcat(s3,s2);

  printf("\nResultado da concatenação das duas strings auxiliares 's1' e 's2' numa outra string auxiliar 's3': %s; ",s3);

  l3= Mystrlen(s3);
  printf("O comprimento desta nova string 's3' é: %d\n",l3);
  
  free(s1);
  free(s2);
  free(s3);
  
  return(0);
}

  
