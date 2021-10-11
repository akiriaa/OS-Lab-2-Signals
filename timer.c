/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int alarmNum = 0;
time_t start;
time_t end;

void handler(int signum)
{ //signal handler
  alarmNum +=1;
  printf("Hello World!\n");
  alarm(1);
  //exit(1); //exit after printing
}

void handler2(int signum){
  time_t runtime;
  end = time(NULL);
  runtime = end-start;
  printf("\nNumber of alarms: %d", alarmNum);
  printf("\nRuntime: %d \n", (int)runtime);
  exit(0);
}

int main(int argc, char * argv[])
{
  start = time(NULL);
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, handler2);
  alarm(1); //Schedule a SIGALRM for 1 second
  while(alarm(1)){
    pause();
    printf("Turing was right!\n");
  }
  //while(1); //busy wait for signal to be delivered
  return 0; //never reached
}

