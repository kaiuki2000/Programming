#include <stdio.h>
#include <math.h>

//falta o domínio***
double derivar (double (*f) (double), double x)
{
  double flinha;
  double h=0.00001;
  
  flinha= (f(x+h)-f(x))/h;

  return(flinha);
}



double cos4x (double x)
{
  double y;
  y= cos(4*x);

  return(y);
}



double exp6x (double x)
{
  double y;
  y= exp(6*x);

  return(y);
}



double funcaogrande (double x)
{
  double y;
  y= 4*cos(2*x)*sin(3*x);

  return(y);
}



int main()
{
  int dev;
  double x,y,real,jgdif;
  char verif;
  
  printf("Calculadora de derivadas\n");
  
  while(1)
    {
      printf("\nMenu:\nQual a função cuja derivada pretende calcular?\n\n(1)-sen(x)\n(2)-cos(4x)\n(3)-tan(x)\n(4)-arcsen(x)\n(5)-arccos(x)\n(6)-ln(x)\n(7)-log(x)\n(8)-exp(6x)\n(9)-4cos(2x)sen(3x)\n\n");
      scanf("%d",&dev);
  
      printf("A função escolhida foi (%d)\n\n",dev);
      printf("Em que valor de x pretende calcular a derivada?\n");
      scanf("%lf",&x);
  
      printf("Valor lido: x=%lf\n\n",x);

      switch(dev)
	{
	case 1 :
	  y= derivar(sin,x);
	  real=cos(x);
	  printf("Valor calculado: (sen)'(%lf)= %lf (h=0,00001)\n",x,y);
	  printf("Valor exato: (sen)'(%lf)= %lf\n",x,real);
	  jgdif= fabs(real-y);
	  printf("A diferença entre o valor calculado e o exato é: %lf", jgdif);
	  break;

	case 2 :
	  y= derivar(cos4x,x);
	  real=-4*sin(4*x);
	  printf("Valor calculado: [cos(4x)]'(%lf)= %lf (h=0,00001)\n",x,y);
	  printf("Valor exato: [cos(4x)]'(%lf)= %lf\n",x,real);
	  jgdif= fabs(real-y);
	  printf("A diferença entre o valor calculado e o exato é: %lf", jgdif);
	  break;

	case 3 :
	  y= derivar(tan,x);
	  real=1+(tan(x)*tan(x));
	  printf("Valor calculado: (tan)'(%lf)= %lf (h=0,00001)\n",x,y);
	  printf("Valor exato: (tan)'(%lf)= %lf\n",x,real);
	  jgdif= fabs(real-y);
	  printf("A diferença entre o valor calculado e o exato é: %lf", jgdif);
	  break;

	case 4 :
	  y= derivar(asin,x);
	  real=1/(sqrt(1-x*x));
	  printf("Valor calculado: (arcsen)'(%lf)= %lf (h=0,00001)\n",x,y);
	  printf("Valor exato: (arcsen)'(%lf)= %lf\n",x,real);
	  jgdif= fabs(real-y);
	  printf("A diferença entre o valor calculado e o exato é: %lf", jgdif);
	  break;

	case 5 :
	  y= derivar(acos,x);
	  real=-1/(sqrt(1-x*x));
	  printf("Valor calculado: (arccos)'(%lf)= %lf (h=0,00001)\n",x,y);
	  printf("Valor exato: (arccos)'(%lf)= %lf\n",x,real);
	  jgdif= fabs(real-y);
	  printf("A diferença entre o valor calculado e o exato é: %lf", jgdif);
	  break;
      
	case 6 :
	  y= derivar(log,x);
	  real=1/x;
	  printf("Valor calculado: (ln)'(%lf)= %lf (h=0,00001)\n",x,y);
	  printf("Valor exato: (ln)'(%lf)= %lf\n",x,real);
	  jgdif= fabs(real-y);
	  printf("A diferença entre o valor calculado e o exato é: %lf", jgdif);
	  break;

	case 7 :
	  y= derivar(log10,x);
	  real=1/(x*log(10));
	  printf("Valor calculado: (log)'(%lf)= %lf (h=0,00001)\n",x,y);
	  printf("Valor exato: (log)'(%lf)= %lf\n",x,real);
	  jgdif= fabs(real-y);
	  printf("A diferença entre o valor calculado e o exato é: %lf", jgdif);
	  break;

	case 8 :
	  y= derivar(exp6x,x);
	  real=6*exp(6*x);
	  printf("Valor calculado: (exp(6x))'(%lf)= %lf (h=0,00001)\n",x,y);
	  printf("Valor exato: (exp(6x))'(%lf)= %lf\n",x,real);
	  jgdif= fabs(real-y);
	  printf("A diferença entre o valor calculado e o exato é: %lf", jgdif);
	  break;

	case 9 :
	  y= derivar(funcaogrande,x);
	  real=-8*sin(2*x)*sin(3*x)+12*cos(2*x)*cos(3*x);
	  printf("Valor calculado: (4cos(2x)sen(3x))'(%lf)= %lf (h=0,00001)\n",x,y);
	  printf("Valor exato: (4cos(2x)sen(3x))'(%lf)= %lf\n",x,real);
	  jgdif= fabs(real-y);
	  printf("A diferença entre o valor calculado e o exato é: %lf", jgdif);
	  break;
      
	default :
	  printf("***Não escolheu uma função!***\n");
	}
  
  
      printf("\n\nQuer repetir?\n\n(a)-sim\n(b)-não\n");
      scanf(" %c",&verif);
  
      if(verif=='b')
	break;
    }
  
  return (0);
}
  
