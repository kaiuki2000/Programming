#include <stdio.h>
#include <string.h>
#include <stdlib.h>



size_t strlen (const char *s)
{
  int l,i;
  i=0;
  l=0;
  while(s[i]!=0)
    {
      l++;
      i++;
    }
  return (l);
}

char * strcpy (char *str1, const char *str2)
{
  int i,d;
  d=strlen(str2);
  str1=(char*) malloc ((d+1)*sizeof (char));
  i=0;
  while(1)
    {
      str1[i]=str2[i];
      if(str2[i]==0)
	{
	  break;
	}

      i++;
    }
  return(str1);
}



char * mystrcat (char *str1, const char *str2)

{
  char *str3;
  int a,b,i;
  i=0;
  a=0;
  b=0;
  a=strlen(str1);
  printf("a:%d\n",a);
  b=strlen(str2);
  printf("b:%d\n",b);
  
  str3=(char*) malloc ((a+b+1)*sizeof (char));
  while(i<a)
    {
      str3[i]=str1[i];
      i++;
      }
  while(i>=a && i<a+b)
    {
      str3[i]=str2[i-a];
      i++;
    }
  return(str3);
}


	       
int main(int argc, char **argv)
{
  int c,d;
  char *str1,*str3;

  c = strlen(argv[1]);
  d = strlen(argv[2]);
  
  if(argc!=3)
    {
      printf("Input inválido!!\n\nO programa deve ser escrito da seguinte forma: ./Prog4.4 <string1> <string2>");
      return(0);
    }

  str3= mystrcat(argv[1],argv[2]);



  str1=strcpy(argv[1],argv[2]);
  
  

  printf("A segunda string copiada para a primeira: %s\n",str1);
  printf("Os comprimentos das primeira e segunda strings são, respetivamente: %d e %d\n",c,d);
  printf("A junção das strings é: %s\n",str3);

  

  free(str3);
  free(str1);
  return(0);
}
