#include "kernel/types.h"
#include "user/user.h"
int 
main(int argc, char* argv[]){
	int x;
	if (argc<2){
	   fprintf(2,"usage: sleep time\n");
	   exit(1);
    }
   	x = atoi(argv[1]);
	fprintf(1,"x=%d\n",x);
  	sleep(x);
	exit(0);
}
