#include "kernel/types.h"
#include "user/user.h"

int main()
{
  char buf, msg = '0';
  int parent_fd[2], child_fd[2];
  if (pipe(parent_fd) != 0 || pipe(child_fd) != 0)
  {
    printf("pipe() failed\n");
    exit(1);
  }
  int pid = fork();
  if (pid == 0)
  {
    read(parent_fd[0], &buf, 1);
    printf("%d: received ping\n",getpid());
    write(child_fd[1], &msg, 1);
  }
  else
  {
    write(parent_fd[1],&msg,1);
    read(child_fd[0],&buf,1);
    printf("%d: received pong\n",getpid());
  }
  exit(0);
}