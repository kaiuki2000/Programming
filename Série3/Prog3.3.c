#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct planeta
{
  char nome[9];
  float distanciasol;
  float massa;
  float inclinacao;
  float raio;
  float temporevolucao;
  float tempotranslacao;
  int numerosatelites;
  char tipoplaneta[13];
};



void print_planeta (struct planeta *p1)
{
  printf ("\nNome:'%s'\n", p1->nome);
  printf ("\nDistância ao Sol:'%.2lf'km\n", p1->distanciasol);
  printf ("\nMassa:'%.2lf'kg\n", p1->massa);
  printf ("\nInclinação:'%.2lf'º em relação à Terra\n", p1->inclinacao);
  printf ("\nRaio:'%.2lf'km\n", p1->raio);
  printf ("\nTempo de revolução:'%.2lf'dias terrestres\n", p1->temporevolucao);
  printf ("\nTempo de tranlação:'%.2lf'anos terrestres\n", p1->tempotranslacao);
  printf ("\nNúmero de satélites naturais:'%d'\n", p1->numerosatelites);
  printf ("\nÉ planeta anão?:'%s'\n", p1->tipoplaneta);
}



int main(int argc, char **argv)
{
  struct planeta planetas[10] = {
				 {"Mercúrio", 57.9e6, 3.285e23, 7.1, 2440, 58, 0.24, 0, "Não"},
				 {"Vénus", 108.2e6, 4.867e24, 3.4, 6052, 243, 0.62, 0, "Não"},
				 {"Terra", 150e6, 5.972e24, 0.0, 6378, 1, 1, 1, "Não"},
				 {"Marte", 227e6, 6.39e23, 1.9, 3397, 1.03, 1.9, 2, "Não"},
				 {"Júpiter", 778e6, 1.898e27, 1.3, 71492, 0.41, 11.96, 63, "Não"},
				 {"Saturno", 1432e6, 5.683e26, 2.5, 60268, 0.43, 29.4, 43, "Não"},
				 {"Urano", 2870e6, 8.681e25, 0.8, 26000, 0.72, 84, 15, "Não"},
				 {"Neptuno", 4500e6, 1.024e26, 1.8, 24764, 0.67, 165, 13, "Não"},
				 {"Plutão", 5874e6, 1.32e22, 17.2, 1187, 6.38, 248, 0, "Sim"},
				 {"Ceres", 413.7e6, 8.958e20, 10.6, 475, 0.32, 4.61, 0, "Sim"}
  };

  if(strcmp(argv[1],"Mercúrio")==0)
    {
      if(argc==3)
	{
	  printf("Mercúrio:\n");
	  if (strcmp(argv[2],"Massa")==0)
	    printf("Massa: %.2lf kg\n", planetas[0].massa);
	}
      else
	print_planeta (&planetas[0]);

    }
      
  if(strcmp(argv[1],"Vénus")==0)
    {
      print_planeta (&planetas[1]);
    }
  if(strcmp(argv[1],"Terra")==0)
    {
      print_planeta (&planetas[2]);
    }
  if(strcmp(argv[1],"Marte")==0)
    {
      print_planeta (&planetas[3]);
    }
  if(strcmp(argv[1],"Júpiter")==0)
    {
      print_planeta (&planetas[4]);
    }
  if(strcmp(argv[1],"Saturno")==0)
    {
      print_planeta (&planetas[5]);
    }
  if(strcmp(argv[1],"Urano")==0)
    {
      print_planeta (&planetas[6]);
    }
  if(strcmp(argv[1],"Neptuno")==0)
    {
      print_planeta (&planetas[7]);
    }
  if(strcmp(argv[1],"Plutão")==0)
    {
      print_planeta (&planetas[8]);
    }
  if(strcmp(argv[1],"Ceres")==0)
    {
      print_planeta (&planetas[9]);
    }

  if(strcmp(argv[1],"Massa")==0)
    {
      printf("Massa de Mercúrio: %lg kg\n",planetas[0].massa);
      printf("Massa de Vénus: %lg kg\n",planetas[1].massa);
      printf("Massa de Terra: %lg kg\n",planetas[2].massa);
      printf("Massa de Marte: %lg kg\n",planetas[3].massa);
      printf("Massa de Júpiter: %lg kg\n",planetas[4].massa);
      printf("Massa de Saturno: %lg kg\n",planetas[5].massa);
      printf("Massa de Urano: %lg\n",planetas[6].massa);
      printf("Massa de Neptuno: %lg\n",planetas[7].massa);
      printf("Massa de Plutão: %lg\n",planetas[8].massa);
      printf("Massa de Ceres: %lg\n",planetas[9].massa);
    }
  return(0);
}
	  
