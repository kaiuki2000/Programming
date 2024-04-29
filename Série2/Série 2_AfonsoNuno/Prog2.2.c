#include <stdio.h>
#include <math.h>



//Declaração da função factorial, definida por recorrência.
      
double Fac(int x)
{
  double f;
  if (x==0)
    {
      return 1;
    }
  f= x*Fac(x-1);
  return f;
}



//Declaração da função cosseno (Calcula o cosseno de x com erro inferior a 10⁻¹⁰).

double cosnosso(double x)
{
  double cosi, coslinha;
  int i;
  i=0;
  cosi=0;
  while (1)
    {
      coslinha=cosi;
      cosi = cosi +(pow(-1,i)*(pow(x,2*i)/Fac(2*i)));
      i++;
      if(fabs(cosi-coslinha)<1e-10)
      {
	break;
      }
    }
      
  return (cosi);
}


//Função principal.

int main (int argc, char **argv)
{
  int t1;
  double cosi,x;
  //Testes para o valor introduzido como argumento da função.
  t1=sscanf(argv[1],"%lf",&x);
  if (argc!=2)
    {
      printf("O programa deve ser executado na forma:\n\n    ./Prog2.2 <x>\n\n em que x é o valor do ângulo.\n");
      return (0);
    }
  if(t1!=1)
    {
      printf("\nA leitura é inválida\n\n");
      return (0);
    }
  //Caso x<0, teremos que o transformar num valor positivo para o cálculo do cosseno.
  if (x<0)
    {
      x=fmod (x,2*((M_PI)))+2*((M_PI));
    }
  else
    {
      x=fmod (x,2*((M_PI)));
    }
		    
  //Cálculo do cosseno de x, recorrendo à função cosseno definida anteriormente.		
  cosi =cosnosso(x);
  printf("\n\nO valor do nosso programa: cos (%lf) = %.10lf\n\n\n",x,cosi);
  printf("O valor real: cos (%lf) = %.10lf\n\n\n",x, cos(x));
  return (0);
}

	      
	    
	           
