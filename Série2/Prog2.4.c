#include <stdio.h>

int main(int argc, char **argv)
{
  //Estrutura do dia na qual vamos ter 3 variáveis: uma para as horas, outra para os minutos e outra para os segundos.
  struct dia
  {
    int hora;
    int minutos;
    int segundos;
  };

  
  //Atribuição de variáveis.
  int s1, s2;
  double m1, m2;

  
  //Vamos criar duas variáveis da função estrutura.
  struct dia dia1, dia2, dia3;
  

  //Teste para a leitura das horas.
  if(argc!=3)
    {
      printf("O programa deve ser escrito na forma:\n\n ./Prog2.4 <hora:minuto:segundo> <hora:minuto:segundo>\n\n");
      return (0);
    }
  
  //Leitura dos valores escritos e atribuir, respetivamente, esses valores às suas variáveis.
  sscanf(argv[1],"%d:%d:%d", &dia1.hora, &dia1.minutos, &dia1.segundos);
  sscanf(argv[2],"%d:%d:%d", &dia2.hora, &dia2.minutos, &dia2.segundos);
  
  //Testes para as horas.
  if ((dia1.hora<0 || dia1.hora>23) || (dia2.hora<0 || dia2.hora>23))
    {
      printf("As horas introduzidas são inválidas\n");
      return(0);
    }
  
  //Testes para os minutos.
  if ((dia1.minutos<0 || dia1.minutos>60) || (dia2.minutos<0 || dia2.minutos>60))
    {
      printf("As horas introduzidas são inválidas\n");
      return(0);
    }
  
  //Testes para os segundos.
  if ((dia1.segundos<0 || dia1.segundos>60) || (dia2.segundos<0 || dia2.segundos>60))
    {
      printf("As horas introduzidas são inválidas\n");
      return(0);
    }
  
  //Passar a hora dada para segundos.
  printf("As horas introduzidas são: \n\n(1): %d horas %d minutos %d segundos \n(2): %d horas %d minutos %d segundos\n",dia1.hora, dia1.minutos, dia1.segundos, dia2.hora, dia2.minutos, dia2.segundos); 
  s1= dia1.hora*3600 + dia1.minutos*60 +  dia1.segundos;
  s2= dia2.hora*3600 + dia2.minutos*60 +  dia2.segundos;

  
  //Imprimir os segundos respetivos.
  printf("\nDesde o início do dia (1) passaram %d segundos\nDesde o início do dia (2) passaram %d segundos\n", s1, s2);

  
  //Passar a hora dada para minutos.
  m1= dia1.hora*60 + dia1.minutos + ((double)dia1.segundos/60);
  m2= dia2.hora*60 + dia2.minutos + ((double)dia2.segundos/60);

  
  //Imprimir os minutos respetivos.
  printf("\nDesde o início do dia (1) passaram %.2lf minutos\nDesde o início do dia (2) passaram %.2lf minutos\n", m1, m2);
  
  
  //Somar as horas, minutos e segundos  dados.
  dia3.hora= dia1.hora + dia2.hora;
  dia3.minutos= dia1.minutos + dia2.minutos;
  dia3.segundos= dia1.segundos + dia2.segundos;
  
  
  //Caso em que os segundos ultrapassem o limite, aumentar um minuto e passar para os segundos para o intervalo correto (0,59). 
  if (dia3.segundos > 59)
    {
      dia3.segundos-=60;
      dia3.minutos+= 1;
    }
  
  //Caso em que os minutos ultrapassem o limite, aumentar uma hora e passar os minutos para o intervalo correto (0,59).
  if (dia3.minutos > 59)
    {
      dia3.minutos-=60;
      dia3.hora+= 1;
    }
  
  //Caso em que as horas ultrapassem o limite passar para o intervalo correto (0,24).
  if (dia3.hora > 23)
    {
      dia3.hora-=24;
    }
  
  //Imprimir as novas horas.
  printf("\nAs novas horas (resultantes da soma das duas horas introduzidas) são: %d:%d:%d\n",dia3.hora, dia3.minutos, dia3.segundos);
  return (0);
}
