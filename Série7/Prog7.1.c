#include <stdio.h>
#include <math.h>

double integrar(double (*f) (double), double a, double b)
{
  int n=1e6,i=0,jgdiff;
  double c,area=0,troca;

  if(b<a)
    {
      troca=a;
      a=b;
      b=troca;
      jgdiff=1;
    }
  
  c=  fabs(b-a)/n;

  for(i=0;i<n;i++)
    {
      area+= ((f(a)+f(a+c))/2)*c;
      a+=c;
    }
  
  if(jgdiff==1)
    return(-area);
  else
    return(area);
}

 

double funcao2 (double x)
{
  double y;
  y= 5*cos(2*x)*exp(-0.2*x);
  return(y);
}


double funcao4 (double x)
{
  double y;
  y= 7*pow(x,5)-3*pow(x,2);
  return(y);
}


double funcao6 (double x)
{
  double y;
  y= (1/sqrt(M_PI))*exp(-(x*x));
  return(y);
}


int main ()
{
  
  int prime;
  double a,b,y,z;
  char verif;

  printf("Calculadora de integrais\n");
  
  while(1)
    {
      printf("------------------------------------------------------------------------------------\n");
      printf("\nMenu:\nQual a função cujo integral pretende calcular?\n\n(1)-> sen(x)\n(2)-> 5cos(2x)*exp(-0.2*x)\n(3)-> sqrt(x)\n(4)-> 7x⁵-3x²\n(5)->exp(x)\n(6)-> 1/(sqrt(π))*exp(-(x*x))\n\n");
      scanf("%d",&prime);
  
      printf("A função escolhida foi (%d)\n\n",prime);
      printf("Qual o intervalo para o qual quer calcular o integral? Escreva na notação: [a,b]\n");
      scanf(" [%lf,%lf]",&a,&b);
  
      printf("Valores lidos: a=%lf; b=%lf\n\n",a,b);

      switch(prime)
	{
	case 1 :
	  y= integrar(sin,a,b);
	  printf("Valor calculado: ∫sen(x)dx= %lf (No intervalo: [%lf,%lf])\n",y,a,b);
	  break;

	case 2 :
	  y= integrar(funcao2,a,b);
	  printf("Valor calculado: ∫5cos(2x)*exp(-0.2*x)dx= %lf (No intervalo: [%lf,%lf])\n",y,a,b);
	  break;

	case 3 :
	  y= integrar(sqrt,a,b);
	  printf("Valor calculado: ∫sqrt(x)dx= %lf (No intervalo: [%lf,%lf])\n",y,a,b);
	  break;

	case 4 :
	  y= integrar(funcao4,a,b);
	  printf("Valor calculado: ∫7x⁵-3x²(x)dx= %lf (No intervalo: [%lf,%lf])\n",y,a,b);
	  break;

	case 5 :
	  y= integrar(exp,a,b);
	  printf("Valor calculado: ∫exp(x)dx= %lf (No intervalo: [%lf,%lf])\n",y,a,b);
	  break;
      
	case 6 :
          y= integrar(funcao6,a,b);
	  printf("Valor calculado: ∫1/(sqrt(π))*exp(-(x*x))dx= %lf (No intervalo: [%lf,%lf])\n",y,a,b);
	  break;

	default :
	  printf("***Não escolheu uma função!***\n");
	}
      
      printf("\n\nQuer repetir?\n\n(a)-sim\n(b)-não\n");
      scanf(" %c",&verif);
  
      if(verif=='b')
	break;

      printf("\n");
      
    }
  return(0);
}
  
