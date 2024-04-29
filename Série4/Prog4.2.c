#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct{
  double real;
  double i;
}Complexo;



void somar(Complexo *z1, Complexo *z2, Complexo *z3)
{
  z3->real = z1->real + z2->real;
  z3->i = z1->i + z2->i;
}



void subtrair(Complexo *z1, Complexo *z2, Complexo *z3)
{
  z3->real = z1->real - z2->real;
  z3->i = z1->i - z2->i;
}



void multiplicar(Complexo *z1, Complexo *z2, Complexo *z3)
{
  z3->real = (z1->real*z2->real)-(z1->i*z2->i);
  z3->i = (z1->i*z2->real)+(z1->real*z2->i);
}



void dividir(Complexo *z1, Complexo *z2, Complexo *z3)
{
  z3->real = ((z1->real*z2->real) + (z1->i*z2->i))/(z2->real*z2->real+z2->i*z2->i);
  z3->i = ((z2->real*z1->i)-(z1->real*z2->i))/(z2->real*z2->real+z2->i*z2->i);
}



double modulo(Complexo *z1)
{
  double x;
  x = sqrt((z1->real*z1->real) + (z1->i*z1->i));
  return(x);
}



int main (int argc, char **argv)
{
  Complexo z1,z2,z3;
  double modulo1;
  
  sscanf(argv[2],"%lf",&z1.real);
  sscanf(argv[3],"%lf",&z1.i);
  sscanf(argv[4],"%lf",&z2.real);
  sscanf(argv[5],"%lf",&z2.i);

  if (strcmp(argv[1],"somar")==0)
    {
      somar(&z1,&z2,&z3);
      printf("Soma: (%.2lf + %.2lfi) + (%.2lf + %.2lfi) = %.2lf +%.2lfi\n",z1.real,z1.i,z2.real,z2.i, z3.real, z3.i);
      return (0);
    }

  if (strcmp(argv[1],"subtrair")==0)
    {
      subtrair(&z1,&z2,&z3);
      printf("Subtrair: (%.2lf + %.2lfi) - (%.2lf + %.2lfi) = %.2lf +%.2lfi\n",z1.real,z1.i,z2.real,z2.i, z3.real, z3.i);
      return (0);
    }

  if (strcmp(argv[1],"multiplicar")==0)
    {
      multiplicar(&z1,&z2,&z3);
      printf("Multiplicar: (%.2lf + %.2lfi) * (%.2lf + %.2lfi) = %.2lf +%.2lfi\n",z1.real,z1.i,z2.real,z2.i, z3.real, z3.i);
      return (0);
    }

  if (strcmp(argv[1],"dividir")==0)
    {
      dividir(&z1,&z2,&z3);
      printf("Divisão: (%.2lf + %.2lfi) / (%.2lf + %.2lfi) = %.2lf +%.2lfi\n",z1.real,z1.i,z2.real,z2.i, z3.real, z3.i);
      return (0);
    }
      
  if (strcmp(argv[1],"modulo")==0)
    {
      modulo1 = modulo(&z1);
      printf("Modulo: |%.2lf + %.2lfi|= %lf\n",z1.real,z1.i, modulo1);
      return (0);
    }
      
  return(0);
}
  
