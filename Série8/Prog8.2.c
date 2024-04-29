#include <stdio.h>

int main(int argc, char **argv)
{
  int n1,N,n2;
  sscanf(argv[1],"%d",&N);
  for(n1=0;n1<N;++n1)
    {
      for(n2=n1+1;n2<N;++n2)
	printf(" ");
      for(n2=0;n2<=n1;++n2)
	printf("* ");
      printf("\n");
    }
  return(0);
}
    
