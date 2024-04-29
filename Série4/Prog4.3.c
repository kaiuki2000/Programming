#include <stdio.h>
#include <math.h>



int conta_numeros(double y)
{
  double  pint, eh;
  int i;
  i=0;
      printf("---> y: %lf\n", y);
  while(fabs(y)>1e-20)
    {

      printf("y: %lf\n", y);
      y=y/10;
      modf(y,&pint);
      y=pint;
      ++i;
    }
  return (i);
}




void armstrong (int z,int n)
{
  int i,r,soma,num;
  double pint,ah;
  i=0;
  soma=0;
  num=z;
  
  while(i<n)
    {
      r= z % 10;
      soma+= pow(r,n);   
      z=z/10;
      modf(z,&pint);
      printf("(%d) z: %d       pint: %lf\n", n, z,pint);
      z=pint;
      ++i;
    }
  
  if(soma==num)
    printf("%d é número de Armstrong\n", num);
}









int main(int argc, char **argv)
{
  double x;
  int i,N;
  
  i=1;
  sscanf(argv[1],"%lf",&x);
  
  while(i<=x)
    {
      N = conta_numeros(i);

      printf("i: %d ; N: %d\n", i, N);
      //armstrong(i, N);
      ++i;
    }
  return (0);
}
 
