#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <locale.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char **argv)
{
  int i=0;
  DIR *d1;
  char str1[32],s[512];
  
  struct dirent *dent;
  struct stat stat1;
  struct tm *tm;

  if((argc!=3)&&(argc!=1))
    {
      printf("***Erro***\nEscreva o programa na forma:\n\n./Prog8.4 [-l] [diretoria] em que os elementos entre parêntesis retos são facultativos.\n");
      return(0);
    }

  
  if(argc==1)
    d1 = opendir("./");
  else if(strcmp(argv[1],"-l")!=0){
    printf("***Erro***\nEscreva o programa na forma:\n\n./Prog8.4 [-l] [diretoria] em que os elementos entre parêntesis retos são facultativos.\n");
    return(0);}
  else
    d1= opendir(argv[2]);

  
  if(argc==1)
    {
      printf("\n");
      while ((dent=readdir(d1))!= NULL)
	{
	  if((strcmp(dent->d_name,".")==0)||(strcmp(dent->d_name,"..")==0))
	    continue;
	  printf("%-20s  ", dent->d_name);
	  i+=1;
	  if(i%8==0)
	    printf("\n");
      
	}
      printf("\n");
    }

  
  if(argc==3)
    {
      printf("\n");
      while ((dent=readdir(d1))!= NULL)
	{
	  if((strcmp(dent->d_name,".")==0)||(strcmp(dent->d_name,"..")==0))
	    continue;
	  sprintf(s,"%s/%s",argv[2],dent->d_name);
	  
#ifdef _WIN32
	  stat(s, &stat1);

#else
	  lstat(s, &stat1);

#endif
	  
	  setlocale(LC_TIME,"pt_PT.UTF-8");
	  tm= localtime(&stat1.st_mtime);
	  strftime(str1,32,"%b %d %H:%M",tm);
	  printf("%s",str1);
	  printf("%10ld  %20s", stat1.st_size, dent->d_name);
	  printf("\n");
	}
      
    }



  
  printf("\n");
  closedir(d1);
  return 0;

}
