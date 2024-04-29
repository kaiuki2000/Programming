#include <stdio.h>
#include <stdlib.h>


void binario(char *bi,int n)
{
   int i,j,intermedio;
  i=0;
  j=0;
      while(1)
	{
	  bi[i]= n % 2;
	  bi[i]+=48;
	  n/=2;
	  if(n==0)
	    break;
	  i++;
	}

      bi[i+1]=0;

      while(j<(i/2))
	{
	  intermedio = bi[j];
	  bi[j] = bi[i-j];
	  bi[i-j] = intermedio;
	  j++;
	}
}





void octal(char *oc,int n)
{
  int i,intermedio;
  i=0;
      while(1)
	{
	  oc[i]= n % 8;
	  oc[i]+=48;
	  n/=8;
	  i++;
	  if(n==0)
	    break;
	}

      oc[i]=0;

      intermedio = oc[0];
      oc[0] = oc[i-1];
      oc[i-1] = intermedio;

}




void hexadecimal (char *hex, int n)
{
  int i,j,intermedio;
  i=0;
  j=0;
      while(1)
	{
	  hex[i]= n % 16;
	  if (hex[i]<10)
	    hex[i]+=48;
	 else
	    hex[i]+=55;
	  n/=16;
	  if(n==0)
	    break;
	  i++;
	}

      hex[i+1]=0;

      while(j<(i/2))
	{
	  intermedio = hex[j];
	  hex[j] = hex[i-j];
	  hex[i-j] = intermedio;
	  j++;
	  }
}
	  
	    





  int main()
{
  int i;
  char bi[100], oc[4], hex[3];
  for(i=0;i<256;i++)
    {
      octal(oc,i);
      hexadecimal(hex,i);
      binario(bi,i),
      printf("Dec: %-3d   Bin: %-8s   Oct: %-3s   Hex: %-2s \n",i,bi,oc,hex);
    }
  return(0);
}
  
  
