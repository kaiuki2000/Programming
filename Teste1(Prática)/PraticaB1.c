#include <stdio.h>


void octal (int n,char *oc){ //A função 'octal' faz a conversão da base decimal para a base octal (potências de 8).
  int aux,i=0,j=0;
  while(n!=0)
    {
      oc[i]=(n%8)+48;
      n/=8;
      i++;
    } oc[i]=0;
  
  for(j=0;j<i/2;j++)
    {
      aux=oc[j];
      oc[j]=oc[i-1-j];
      oc[i-1-j]=aux;
    }}


void hexadecimal (int n, char *hex){ //A função 'hexadecimal' faz a conversão da base decimal para a base hexadecimal (potencias de 16-> são utilizadas as letras A-F para o efeito).
  int aux,i=0,j=0;
  while(n!=0)
    {
      hex[i]=(n%16);
      n/=16;
      if(hex[i]<10){
	hex[i]+=48;}else{
	hex[i]+=55;}
      i++;
    } hex[i]=0;

  for(j=0;j<i/2;j++)
    {
      aux=hex[j];
      hex[j]=hex[i-1-j];
      hex[i-1-j]=aux;
    }}


void binario (int n, char *bin){ //A função 'binário' faz a conversão da base decimal para a base binária (potências de 2).
    int aux,i=0,j=0;
  while(n!=0)
    {
      bin[i]=(n%2)+48;
      n/=2;
      i++;
    } bin[i]=0;

  for(j=0;j<i/2;j++)
    {
      aux=bin[j];
      bin[j]=bin[i-1-j];
      bin[i-1-j]=aux;
    }}

  		  
int main(int argc, char **argv)
{
  int i=0;
  char oc[10], hex[10], bin[10];
  
  if(argc!=1){
    perror("***Erro***\nNúmero de argumentos inválido!");
    printf("\nO programa vai agora terminar...\nPressione ENTER...");
    getchar();
    return(0);}

   printf("%-3d %-8d %-3d %-2d\n",0,0,0,0); //As minhas funções ficaram definidas de tal modo que não funcionam para 0. Daí ser necessário esta adaptação. Seria, no entanto, possível alterar a função de modo a que funcionasse, também, para 0 (editar condição inicial while(n!=0)). 
  for(i=1;i<256;i++)
    {
  octal(i,oc);
  hexadecimal(i,hex);
  binario(i,bin);
  printf("%-3d %-8s %-3s %-2s\n",i,bin,oc,hex);
    }

  return(0);
}
