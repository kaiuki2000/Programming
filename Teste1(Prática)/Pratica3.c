#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Função de ajuda.
void help(){
  printf("O programa deve ser escrito na forma: ./Pratica 3 <N> em que N é o número máximo até ao qual se irá averiguar a existência de números de Armstrong.\n\nO programa vai agora terminar...\nPressione ENTER...");
  getchar();
  exit(0);}


int algarismos (int n){
  int contador=0;
  while(n!=0)
    {
      n/=10;
      contador+=1;
    }
  
  return(contador);}


int Armstrong (int n,int al,int *num){
  int i=0,soma=0,no=n;
  while(n!=0)
    {
      num[al-1-i]=(n%10);
      n/=10;
      i++;
    }
  for(i=0;i<al;i++)
    soma+=pow(num[i],al);

  if(soma==no) return(1); // 1->Número de Armstrong.
  else return(0);}        // 0->Não é número de Armstrong.


int main(int argc, char **argv)
{
  int N,j=0,t=0,c=1,alg;
  int *Num;
  FILE *F1;

  F1= fopen("Pratica3.txt","wt");
  if(F1==NULL)
    {
      printf("***Erro na abertura do ficheiro***\n\nO programa vai agora terminar...\nPressione ENTER...");
      fclose(F1);
      getchar();
      return(0);
    }
      
  Num= (int*) malloc (1*sizeof(int));
  
  //Testes ao número de argumentos e aos argumentos propriamente ditos.
  if(argc==1)
    help();
  if(argc!=2)
    {
      printf("***Erro***\nO input introduzido não é válido. Escreva './Pratica3' para obter ajuda.\n\nO programa vai agora terminar...\nPressione ENTER...");
      getchar();
      return(0);
    }
  if(sscanf(argv[1],"%d",&N)!=1)
    {
      printf("***Erro***\nO input introduzido não é válido. Escreva './Pratica3' para obter ajuda.\n\nO programa vai agora terminar...\nPressione ENTER...");
      getchar();
      return(0);
    }

  for(j=1;j<=N;j++)
    {
      alg=algarismos(j);
      Num = (int*) realloc (Num,alg*sizeof(int));
      t=Armstrong(j,alg,Num);
      if(t==1){
	printf("%7d   ",j);
	fprintf(F1,"%7d   ",j);
	if(c%6==0){
	  printf("\n");
	  fprintf(F1,"\n");}
	c+=1;}     
    }

  free(Num);
  fclose(F1);
  return(0);
}
