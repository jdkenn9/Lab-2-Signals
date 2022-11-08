/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int count = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  //exit(1); //exit after printing
}

void new_handler(int signum)
{ //signal handler for CTRL+C 
  signal(signum, SIG_IGN);
  printf("\nran %d times.\n", count);
  exit(1); //exit after printing
}

int main(int argc, char * argv[])
{   
  while(1){//busy wait for signal to be delivered
    signal(SIGINT,new_handler);
    signal(SIGALRM,handler);
    alarm(1);   //Schedule a SIGALRM for 1 second
    sleep(1);
    printf("Turing was right!\n");
    count++;
    
  }
  return 0; //never reached
}
