#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

int power(int x,int y){
  if(y==0){
    return 1;
  }
  if(y==1){
    return x;
  }
  return x*power(x,y-1);
}
int main(){
  struct stat file;
  stat("main.c",&file);
  printf("File size: %ldB\n",file.st_size);
  printf("File size in KB: %1.1lfKB\n",file.st_size/1000.0);
  printf("Last access time: %s", ctime(&file.st_atime));
  printf("Last modification time: %s", ctime(&file.st_mtime));
  printf("Permisissions: %o \n", file.st_mode%(4096));
  printf("Permisissions:");
  int x = file.st_mode%(1024);
  int y;
  char str[] = "rwx";

  for(y=8;y>=0;y--){
    //printf("%d\n",x);
    if(x/power(2,y)==1){
      printf("%c",str[(-y+14)%3]);
    }
    else{
      printf("-");
    }
    x%=power(2,y);
  }
  printf("\n");
  return 0;
}
