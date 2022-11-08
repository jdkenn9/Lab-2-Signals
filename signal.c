/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  //exit(1); //exit after printing
}

int main(int argc, char * argv[])
{   
  while(1){//busy wait for signal to be delivered
    signal(SIGALRM,handler);
    alarm(1); //Schedule a SIGALRM for 1 second
    sleep(1);
    printf("Turing was right!\n");
  }
  return 0; //never reached
}