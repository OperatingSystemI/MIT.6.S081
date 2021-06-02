#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  if(argc==1){
    printf("a number required");
    exit(1);
  }
  int timer = atoi(argv[1]);
  sleep(timer);
  exit(0);
}