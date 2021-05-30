#include"kernel/types.h"
#include"user/user.h"
int main(){
	int pid,fd[2];
	char buf[1];
	if(pipe(fd)==-1){
		fprintf(2,"pipe() error");
		exit(1);
	}
	pid = fork();
	if (pid==0){
		write(fd[1],"1",1);
		fprintf(1,"%d: received ping\n",getpid());
		close(fd[0]);
		close(fd[1]);
		exit(0);
	}else if (pid > 0){
		read(fd[0],buf,1);
		fprintf(1,"%d: received pong\n",getpid());
		close(fd[0]);
		close(fd[1]);
		exit(0);
	}
	close(fd[0]);
	close(fd[1]);
	exit(1);
}

