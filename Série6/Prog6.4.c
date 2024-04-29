#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void**
matx_new(int m, int n, size_t a)
{
  int b;
  void **matriz, *v;

  matriz= malloc(m *sizeof (void*));
  v= malloc(m*n*a);
  
  for(b=0; b<m; ++b)
    matriz[b]= v+b*a*n;

  return matriz;
}

double** leitura (FILE* nome, int*m, int*n)
{
  int i1, i2;
  double**r;
  
  fscanf(nome, "%d %d", m, n);

  r= (double**)matx_new ((*m), (*n), sizeof(double));

  for(i1=0; i1<(*m); ++i1)
    {
      for(i2=0; i2<(*n); ++i2)
	{
      fscanf(nome, "%lf", &r[i1][i2]);
	}
    }

  return r;
}

void impressao(double**matr, int m, int n)
{
  int a, i1;
  printf("O número de linhas da matriz é: %d\n", m);
  printf("O número de colunas da matriz é: %d\n", n);

  for(i1=0; i1<m; ++i1)
    {
      for(a=0; a<n; ++a)
	{
	  printf("%lf ", matr[i1][a]);
	}
      printf("\n");
    }
}

double**soma(double**matr1, double **matr2, double**matr3, int m, int n)
{
  int i1, i2;
  for(i1=0; i1<(m); ++i1)
    {
      for(i2=0; i2<(n); ++i2)
	{
	  matr3[i1][i2]=matr1[i1][i2]+matr2[i1][i2];
	}
    }
  return matr3;
}

double**subtracao(double**matr1, double **matr2, double**matr3, int m, int n)
{
  int i1, i2;
  for(i1=0; i1<(m); ++i1)
    {
      for(i2=0; i2<(n); ++i2)
	{
	  matr3[i1][i2]=matr1[i1][i2]-matr2[i1][i2];
	}
    }
  return matr3;
}

double**produto(double**matr1, double **matr2, double**matr3, int m, int n)
{
  int i1, i2, i3;
  matr3=0;
   
  for(i1=0; i1<m; ++i1)
    {
      for(i2=0; i2<n; ++i2)
	{	 
	  for(i3=0; i3<m; ++i3)
	    {
	      matr3[i1][i2]= matr3[i1][i2]+matr1[i1][i3]*matr2[i3][i2];
	    }
	}
    }
  return matr3;
}


int main(int argc, char**argv)
{
  int m1, n1, m2, n2;
  FILE*matriz1;
  FILE*matriz2;
  double**r, **v, **s;


  if(argc!=4)
    {
      printf("Escreva na linha de comandos da seguinte maneira:\n");
      printf(" ./Programa ficheiro_matriz1 ficheiro_matriz2 operação\n");
      return -1;
    }

  matriz1=fopen(argv[1], "rt");
  matriz2=fopen(argv[2], "rt");

  r=leitura(matriz1, &m1, &n1);

  impressao(r, m1, n1);

  printf("\n");

  v=leitura(matriz2, &m2, &n2);

  impressao(v, m2, n2);

  if(strcmp(argv[3], "soma")==0)
    {
      if(m1!=m2 || n1!=n2)
	{
	  printf("Para a soma ser possivel as duas matrizes tem de ter a mesma dimensao!");
	  return -1;
	}

        s= (double**)matx_new ((m1), (n1), sizeof(double));
	s=soma(r,v,s, m1,n1);
	printf("\n");
        impressao(s, m1, n1);
    }


  
 if(strcmp(argv[3], "subtracao")==0)
    {
      if(m1!=m2 || n1!=n2)
	{
	  printf("Para a subtracao ser possivel as duas matrizes tem de ter a mesma dimensao!");
	  return -1;
	}

        s= (double**)matx_new ((m1), (n1), sizeof(double));
	s=subtracao(r,v,s, m1,n1);
	printf("\n");
        impressao(s, m1, n1);
    }


 if(strcmp(argv[3], "produto")==0)
    {
      if(n1!=m2)
	{
	  printf("Para a multiplicaçao ser possivel o número de colunas da primeira matriz tem de ser igual ao numero de linhas da segunda matriz!");
	  return -1;
	}
  
        s= (double**)matx_new (m1, n2, sizeof(double));
	s=produto(r,v,s, m1, n2);
	printf("\n");
        impressao(s, m1, n2);
    }

  free (s);
 
  return 0;
}
  
