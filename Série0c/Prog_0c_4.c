#include <stdio.h>
int main()
{
  float r, x0, x;
  int i,w,u;
  FILE *br;
  br = fopen("br.txt","rt");
  fscanf(br,"r:%f\nx0:%f\n",&r, &x0);
  printf("r:%f\nx0:%f\n",r, x0);
  while(1)
    {
      w=fscanf(br,"%d: x=%f\n", &i, &x);
      if(w!=2)
	break;
      printf("%d: x=%f\n", i, x);
	
    }
  fscanf(br,"Cada órbita tem %d valores",&u);
  printf("Cada órbita tem %d valores\n",u);
    
  return 0;	 
}
