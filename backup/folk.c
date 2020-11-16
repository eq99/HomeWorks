#include<unistd.h>
#include<stdio.h>
#include<wait.h>

int
main(){

  fork();
  fork();
  fork();

  printf("My pid is %d, My parent is %d\n.", getpid(), getppid());
  printf("学号: 2015301020007\n");
  printf("%d exited...\n",wait(NULL));
}
