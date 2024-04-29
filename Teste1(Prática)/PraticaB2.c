#include <stdio.h>
#include <stdlib.h>

void help(){
  printf("O programa deve ser inciado da seguinte forma:\n\n./PraticaB2 <N> <M>, em que <N> e <M> são números inteiros positivos.\n\nO programa vai agora terminar...\nPressione ENTER...");
  getchar();
  exit(0);}


void ordenacao(double *r, int n){
  int i=0,t;
  double aux;
  while(1){
    t=0;
    for(i=0;i<n-1;i++){
    if(r[i]>r[i+1]){
      aux=r[i];
      r[i]=r[i+1];
      r[i+1]=aux;
      t=1;}}
    if(t==0){break;}}}


int eliminacao(double *r, int n){
  int i=0,c=0;
  for(i=0;i<n-1;i++){
    if(r[i]!=r[i+1]){
      r[c]=r[i];
      c++;}}
  r[c]=r[n-1];
  r= (double*) realloc (r,(c+1)*sizeof(double));
  return(c);}
  

int main(int argc, char **argv)
{
  int N,M,c=0,p,q,i=0,size;
  double *r;
  FILE *F1;
  if(argc!=3){help();}
  if((sscanf(argv[1],"%d",&N)+sscanf(argv[2],"%d",&M))!=2){help();}
  if((N<=0)||(M<=0)){help();}

  F1=fopen("dados.dat","wb");
   if(F1==NULL){
    fclose(F1);
    printf("***Erro***\nOcorreu um erro na abertura do canal de escrita!\nOprograma vai agora terminar...\nPressione ENTER...");
    getchar();
    return(0);}

  r= (double*) malloc ((N*M)*sizeof(double));

  for(p=1;p<=N;p++)
    {
      for(q=1;q<=M;q++)
	{
	  r[c]=(double)p/(double)q;
	  c++;
	}
    }

  printf("Os valores gerados foram:\n");
  while(r[i]!=0){
    printf("%lf\n",r[i]);
    i++;}

  ordenacao(r,(N*M));i=0;
  printf("\nOs valores gerados, após ordenação, foram:\n");
  while(r[i]!=0){
    printf("%lf\n",r[i]);
    i++;}

  size=eliminacao(r,(N*M));i=0;
  printf("\nOs valores gerados, após ordenação e eliminação dos repetidos, foram:\n");
  while(i<size+1){
    printf("%lf\n",r[i]);
    i++;}
  
  if(fwrite(r,sizeof(double),size+1,F1)!=(size+1)){ //Ou, então, provavelmente mais fácil, fwrite(r,sizeof(r),1,F1). O teste seria if(fwrite(r,sizeof(r),1,F1)!=1){perror("fwrite");return(0);}.
    perror("fwrite");
    return(0);}
     
  fclose(F1);
  free(r);
  return(0);
}

      
  
