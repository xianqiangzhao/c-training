#include<stdio.h> 
#include<fcntl.h> 
#include<string.h>  
int main(int argc, char const *argv[])
{    
  char buf[20];
  int fd = open("foo.txt", O_RDWR| O_CREAT | O_APPEND);      
  printf("fd = %d \n", fd);
  write(fd, argv[1], strlen(argv[1]));
  lseek(fd, 0,SEEK_SET);
  read(fd, buf,5);
  printf("buf= %s \n" , buf);
  close(fd);
  return 0; 
}