#include <stdio.h>

int main()
{
  int a,i,m;
  FILE *hue;
    hue = fopen ("hue.txt","wt");
  i=1;
  printf("Digite o número cuja tabuada pretende obter:");
  scanf("%d",&a);
  while (i<=10)
    {
      m= a*i;
      printf("%d*%d=%d\n",a,i,m);
      fprintf (hue,"%d*%d=%d\n",a,i,m);
      ++i;
    }
  fclose (hue);
  return 0;
}
      
