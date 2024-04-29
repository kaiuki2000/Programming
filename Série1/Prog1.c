#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
  double x, y, r, rf,c,n;
  int t1,i;
  // x e y serão as coordenadas do ponto gerado; c será o número de pontos pertencentes ao círculo; t1 será utilizada para o teste da leitura;
  c=0;
  // A função srand permite-nos gerar pontos aleatórios;
  srand(time(NULL));
  printf("Quantos pontos aleatórios pretende gerar?:\n");
  // Teste da leitura;
  t1 = scanf("%lf",&n);
  if(t1!=1)
    {
      printf("A leitura não foi bem sucedida. (Teste=%d)\n",t1);
      return(0);
    }
  if(t1=1)
    printf ("A leitura foi bem sucedida. (Teste=%d)\n",t1);
  // Gerar as coordenadas dos pontos aleatórios;
  for(i=0;i<n;i++)
    {
      x= ((double)rand())/((double)RAND_MAX);
      x= x-0.5;

      y= ((double)rand())/((double)RAND_MAX);
      y= y-0.5;
      // Para o ponto pertencer ao círculo x²+y² (distância à origem) tem que ser menor ou igual 0,25 (raio do círculo ao quadrado); Para isso definimos r=x²+y²;
      r = (x*x)+(y*y);
      
      if(r<=0.25)
	{
	  c=c+1;
	}
    }
  // rf é a razão entre o número de pontos que caíram no círculo e o número de pontos total;
  printf("O número de pontos que caíram dentro do círculo é:%.0f\n",c);
  rf=c/n;
  printf("A razão entre o número de pontos que cairam no círculo e o número de pontos total é:%.5f\n",rf);
  rf=rf*4;  
  printf("A razão entre o número de pontos que cairam no círculo e o número de pontos total multiplicada por 4 é:%.5f\n",rf);
  // A razão c/n quando n toma valores muito elevados tende para pi/4 (razão entre a área do círculo(pi*r²) e a área do quadrado((2r)²=4r²)). Ao multiplicarmos esta razão por 4 torna-se evidente que passa a tender para pi;
  return(0);
}
