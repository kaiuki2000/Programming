#include<stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void Help()
{
  printf("Para que este programa funcione devidamente devem ser introduzidos os argumentos adequados:\n\n*Se pretender somar dois numeros complexos escreva o programa na forma: ./Pratica2 somar <Re(z1)> <Im(z1)> <Re(z2)> <Im(z2)>.\n*Se pretender subtrair dois numeros complexos escreva o programa na forma: ./Pratica2 subtrair <Re(z1)> <Im(z1)> <Re(z2)> <Im(z2)>.\n*Se pretender multiplicar dois numeros complexos escreva o programa na forma: ./Pratica2 multiplicar <Re(z1)> <Im(z1)> <Re(z2)> <Im(z2)>.\n*Se pretender dvidir dois numeros complexos escreva o programa na forma: ./Pratica2 dividir <Re(z1)> <Im(z1)> <Re(z2)> <Im(z2)>.\n*Se pretender obter a norma de um número complexo escreva o programa na forma: ./Pratica2 norma <Re(z1)> <Im(z1)>.\n\nO programa vai agora terminar...\nPressione ENTER...");
  getchar();
  exit(0);  
}
  
typedef struct {
  double real;
  double imag;
  double modulo;
} Complexo;


double modulo(Complexo *z)
{
  return(sqrt(pow(z->real,2)+pow(z->imag,2)));
}


void somar(Complexo *z1, Complexo *z2, Complexo *z3)
{
  z3->real= z1->real + z2->real;
  z3->imag= z1->imag + z2->imag;
  z3->modulo=sqrt(pow(z3->real,2)+pow(z3->imag,2));
}


void subtrair(Complexo *z1, Complexo *z2, Complexo *z3)
{
  z3->real= z1->real - z2->real;
  z3->imag= z1->imag - z2->imag;
  z3->modulo=sqrt(pow(z3->real,2)+pow(z3->imag,2));
} 


void multiplicar(Complexo *z1, Complexo *z2, Complexo *z3)
{
  z3->real = (z1->real*z2->real)-(z1->imag*z2->imag);
  z3->imag = (z1->imag*z2->real)+(z1->real*z2->imag);
  z3->modulo=sqrt(pow(z3->real,2)+pow(z3->imag,2));
}


void dividir(Complexo *z1, Complexo *z2, Complexo *z3)
{
  z3->real = ((z1->real*z2->real) + (z1->imag*z2->imag))/(z2->real*z2->real+z2->imag*z2->imag);
  z3->imag = ((z2->real*z1->imag)-(z1->real*z2->imag))/(z2->real*z2->real+z2->imag*z2->imag);
  z3->modulo=sqrt(pow(z3->real,2)+pow(z3->imag,2)); 
}



int main(int argc, char **argv)
{

  Complexo z1,z2,z3;

  if((argc!=4)&&(argc!=6))
    Help();
  
  if((strcmp(argv[1],"modulo")!=0)&&(strcmp(argv[1],"somar")!=0)&&(strcmp(argv[1],"subtrair")!=0)&&(strcmp(argv[1],"multiplicar")!=0)&&(strcmp(argv[1],"dividir")!=0))
    {
      printf("***Erro***\nA operação introduzida não é válida. Deverá escrever 'somar' 'subtrair' 'multiplicar' 'dividir' ou 'norma'\n\nO programa vai agora terminar...\nPressione ENTER...");
      getchar();
      return(0);
    }

  
  //codigo do módulo.
  if(strcmp(argv[1],"modulo")==0)
    {
      if(argc!=4)
	{
	  printf("***Erro***\nSe pretender obter o módulo de um número complexo escreva o programa na forma:\n\n./Pratica2 modulo <Re(z1)> <Im(z1)>\n\nO programa vai agora terminar...\nPressione ENTER...");
	  getchar();
	  return(0);
	}
      else
	{
	  if((sscanf(argv[2],"%lf",&z1.real)+sscanf(argv[3],"%lf",&z1.imag))!=2)
	    {

	      printf("***Erro***\nSe pretender obter o módulo de um número complexo escreva o programa na forma:\n\n./Pratica2 modulo <Re(z1)> <Im(z1)>\n\nO programa vai agora terminar...\nPressione ENTER...");
	      getchar();
	      return(0);
	    }
	  else
	    {
	      z1.modulo= modulo(&z1);
	      printf("O módulo do número complexo introduzido é:\n\n%.2lf\n",z1.modulo);
	      return(0);
	    }
	}
    }

  
  //código da soma.
  if(strcmp(argv[1],"somar")==0)
    {
       if(argc!=6)
	{
	  printf("***Erro***\nSe pretender obter a soma de dois números complexos escreva o programa na forma:\n\n./Pratica2 soma <Re(z1)> <Im(z1)> <Re(z2)> <Im(z2)>\n\nO programa vai agora terminar...\nPressione ENTER...");
	  getchar();
	  return(0);
	}
      else
	{
	  if((sscanf(argv[2],"%lf",&z1.real)+sscanf(argv[3],"%lf",&z1.imag)+sscanf(argv[4],"%lf",&z2.real)+sscanf(argv[5],"%lf",&z2.imag))!=4)
	    {
	      printf("***Erro***\nSe pretender obter a soma de dois números complexos escreva o programa na forma:\n\n./Pratica2 soma <Re(z1)> <Im(z1)> <Re(z2)> <Im(z2)>\n\nO programa vai agora terminar...\nPressione ENTER...");
	      getchar();
	      return(0);
	    }
	  else
	    {
	      somar(&z1,&z2,&z3);
	      printf("A soma dos números complexos introduzidos é:\n\n(%.2lf + %.2lfi) + (%.2lf + %.2lfi)= %.2lf + %.2lfi\n",z1.real, z1.imag, z2.real, z2.imag, z3.real , z3.imag);
	      return(0);
	    }
	}
    }


  //Código da subtração
   if(strcmp(argv[1],"subtrair")==0)
    {
       if(argc!=6)
	{
	  printf("***Erro***\nSe pretender obter a diferença de dois números complexos escreva o programa na forma:\n\n./Pratica2 soma <Re(z1)> <Im(z1)> <Re(z2)> <Im(z2)>\n\nO programa vai agora terminar...\nPressione ENTER...");
	  getchar();
	  return(0);
	}
      else
	{
	  if((sscanf(argv[2],"%lf",&z1.real)+sscanf(argv[3],"%lf",&z1.imag)+sscanf(argv[4],"%lf",&z2.real)+sscanf(argv[5],"%lf",&z2.imag))!=4)
	    {
	      printf("***Erro***\nSe pretender obter a diferença de dois números complexos escreva o programa na forma:\n\n./Pratica2 soma <Re(z1)> <Im(z1)> <Re(z2)> <Im(z2)>\n\nO programa vai agora terminar...\nPressione ENTER...");
	      getchar();
	      return(0);
	    }
	  else
	    {
	      subtrair(&z1,&z2,&z3);
	      printf("A diferença dos números complexos introduzidos é:\n\n(%.2lf + %.2lfi) - (%.2lf + %.2lfi)= %.2lf + %.2lfi\n",z1.real, z1.imag, z2.real, z2.imag, z3.real , z3.imag);
	      return(0);
	    }
	}
    }

  
  //Código da multiplicação.
   if(strcmp(argv[1],"multiplicar")==0)
    {
       if(argc!=6)
	{
	  printf("***Erro***\nSe pretender obter o produto de dois números complexos escreva o programa na forma:\n\n./Pratica2 soma <Re(z1)> <Im(z1)> <Re(z2)> <Im(z2)>\n\nO programa vai agora terminar...\nPressione ENTER...");
	  getchar();
	  return(0);
	}
      else
	{
	  if((sscanf(argv[2],"%lf",&z1.real)+sscanf(argv[3],"%lf",&z1.imag)+sscanf(argv[4],"%lf",&z2.real)+sscanf(argv[5],"%lf",&z2.imag))!=4)
	    {
	      printf("***Erro***\nSe pretender obter o produto de dois números complexos escreva o programa na forma:\n\n./Pratica2 soma <Re(z1)> <Im(z1)> <Re(z2)> <Im(z2)>\n\nO programa vai agora terminar...\nPressione ENTER...");
	      getchar();
	      return(0);
	    }
	  else
	    {
	      multiplicar(&z1,&z2,&z3);
	      printf("O produto dos números complexos introduzidos é:\n\n(%.2lf + %.2lfi) * (%.2lf + %.2lfi)= %.2lf + %.2lfi\n",z1.real, z1.imag, z2.real, z2.imag, z3.real , z3.imag);
	      return(0);
	    }
	}
    }

   
   //Código da divisão.
    if(strcmp(argv[1],"dividir")==0)
    {
       if(argc!=6)
	{
	  printf("***Erro***\nSe pretender obter a divisão de dois números complexos escreva o programa na forma:\n\n./Pratica2 soma <Re(z1)> <Im(z1)> <Re(z2)> <Im(z2)>\n\nO programa vai agora terminar...\nPressione ENTER...");
	  getchar();
	  return(0);
	}
      else
	{
	  if((sscanf(argv[2],"%lf",&z1.real)+sscanf(argv[3],"%lf",&z1.imag)+sscanf(argv[4],"%lf",&z2.real)+sscanf(argv[5],"%lf",&z2.imag))!=4)
	    {
	      printf("***Erro***\nSe pretender obter a divisão de dois números complexos escreva o programa na forma:\n\n./Pratica2 soma <Re(z1)> <Im(z1)> <Re(z2)> <Im(z2)>\n\nO programa vai agora terminar...\nPressione ENTER...");
	      getchar();
	      return(0);
	    }
	  else
	    {
	      dividir(&z1,&z2,&z3);
	      printf("A divisão dos números complexos introduzidos é:\n\n(%.2lf + %.2lfi) / (%.2lf + %.2lfi)= %.2lf + %.2lfi\n",z1.real, z1.imag, z2.real, z2.imag, z3.real , z3.imag);
	      return(0);
	    }
	}
    }

  return(0);
}

  
