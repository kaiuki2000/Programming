#include <stdio.h>
#include <stdlib.h>



void help()
{
  printf("O programa deverá ser iniciado da seguinte forma:\n\n./Teste1 <string1> <string2> <c>, em que <string1> e <string2> são strings de caracteres e <c> é um caracter.\n\nO programa vai agora terminar...\nPressione ENTER...");
  getchar();
  exit(0);
}



char* Mystrchr(char *s1, int c)
{
  int i=0;
  while(s1[i]!=0){
    if(s1[i]==c)
      return(&s1[i]);
    i++;}
  return(NULL);
}



size_t Mystrspn(char *s1, char *st)
{
  int i=0,j=0,c=0;
  while(s1[i]!=0)
    {
      while(st[j]!=0)
	{
	  if(s1[i]==st[j])
	    {
	      if(st[j]!=96)
		{
		  c++;
		  st[j]=96;
		}
	    }
	  j++;
	}
      i++;
    }
  return(c);  
}



char* Mystrcpy (char *str_to, char *str_from)
{
  int i=0;
  while(str_from[i]!=0)
    {
      str_to[i]=str_from[i];
      i++;
    }
  return(str_to);
}



int Mystrlen(char *s1)
{
  int c=0,i=0;
  while(s1[i]!=0){
    i++;
    c++;}
  return(c);
}



int main(int argc, char **argv)
{
  char c, *p, *string;
  size_t sz;
  int len;
  if(argc!=4)
    help();

  if((sscanf(argv[3],"%c",&c))!=1)
    help();
     
  p=Mystrchr(argv[1],(int)c);
  printf("O resultado obtido com a função Mystrchr foi: %p\n",p);

  sz=Mystrspn(argv[1],argv[2]);
  printf("O resultado obtido com a função Mystrspn foi: %ld\n",sz);

  len= Mystrlen(argv[1]);
  string= (char*) malloc (len*sizeof(char));
  string= Mystrcpy(string,argv[1]);
  printf("O resultado obtido com a função Mystrcpy foi: %s\n",string);

  free(string);
  return(0);
}
