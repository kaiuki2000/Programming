#include <stdio.h>

int mdc (int a,int b)
{
  int c;
  
  while(1)
    {
      c=a%b;
      if (c==0)
	break;
      if (c!=0)
	{
	  a=b;
	  b=c;
	}
    }
  return (b);
}


int main (int argc, char **argv)
{
  int md,mm,A,B;
  
  sscanf(argv[1],"%d",&A);
  sscanf(argv[2],"%d",&B);
  
  md =  mdc (A,B);
  mm = (A*B)/md;
  
  printf("\n\nO máximo divisor comum e o mínimo múltiplo comum entre %d e %d são respetivamente: %d e %d\n\n",A,B,md,mm);
  return(0);
}
