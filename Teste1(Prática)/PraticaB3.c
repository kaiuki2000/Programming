#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void help(){
  printf("O programa deve ser iniciado da seguinte forma:\n\n./PraticaB3 M2m/m2M file_de_leitura file_de_escrita, em que M2m significa passar todo o texto para minúsculas e m2M passar para maiúsculas.\n\nO programa vai agora terminar...\nPressione ENTER...");
  getchar();
  exit(0);}


int main(int argc, char **argv)
{
  FILE *F1, *F2;
  char str[100];
  int i=0;
  
  if(argc!=4)
    help();

  if((strcmp(argv[1],"m2M")!=0)&&(strcmp(argv[1],"M2m")!=0))
    help();
      
  F1=fopen(argv[2],"rt");

  if(F1==NULL)
    {
      fclose(F1);
      printf("Erro na abertura do(s) ficheiro(s).\n");
      return(0);
    }

  F2=fopen(argv[3],"wt");

  if(F2==NULL)
    {
      fclose(F1);
      fclose(F2);
      printf("Erro na abertura do(s) ficheiro(s).\n");
      return(0);
    }
  
  while(1){
  if(strcmp(argv[1],"m2M")==0)
    {i=0;
      if(fgets(str,101,F1)==NULL) break;
	{
	  while(1)
	    {
	      if (str[i]==0)
		break;

	      if (str[i]>96 && str[i]<123)
		str[i]=str[i]-32;

	      i++;
	    }
	  fprintf(F2,"%s",str);
	}
    }

  if(strcmp(argv[1],"M2m")==0)
    {i=0;
      if(fgets(str,101,F1)==NULL) break;
	{
	  while(1)
	    {
	      if (str[i]==0)
		break;

	      if (str[i]>64 && str[i]<91)
		str[i]=str[i]+32;

	      i++;
	    }
	  fprintf(F2,"%s",str);
	}
    }}

  fclose(F1);
  fclose(F2);
  return(0);
}
