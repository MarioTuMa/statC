#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
int main(){
  struct stat file;
  stat("main.c",&file);
  printf("File size: %ldB\n",file.st_size);
  printf("File size in KB: %1.1lfKB\n",file.st_size/1000.0);
  printf("Last access time: %s", ctime(&file.st_atime));
  printf("Last modification time: %s", ctime(&file.st_mtime));
  printf("Permisissions: %o \n", file.st_mode%(4096));
  return 0;
}
