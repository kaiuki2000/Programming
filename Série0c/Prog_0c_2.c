#include <stdio.h>

int main()
{
  int a,i,m;
  FILE *hue;
    hue = fopen ("hue.txt","rt");
  i=1;
  while (i<=10)
    {
      fscanf(hue,"%d*%d=%d\n",&a,&i,&m);
      printf("%d*%d=%d\n",a,i,m);
      ++i;
    }
  fclose (hue);
  return 0;
}
