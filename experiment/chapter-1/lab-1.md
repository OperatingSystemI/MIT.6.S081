# lab-1: Xv6 and Unix utilities

[lab-1](https://pdos.csail.mit.edu/6.828/2020/labs/util.html)

Makefile中添加目标文件

```c
//copy.c
#include "kernel/types.h"
#include "user/user.h"

int main()
{
  char buf[64];
  while (1)
  {
    int n = read(0, buf, sizeof(buf));
    if (n <= 0)
      break;
    write(1, buf, n);
  }
  exit(0);
}

//open.c
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(){
  int fd=open("output.txt",O_WRONLY|O_CREATE);
  write(fd,"ooo\n",4);
  exit(0);
}

//fork.c
#include "kernel/types.h"
#include "user/user.h"

int main()
{
  int pid = fork();
  printf("fork() returned %d\n", pid);
  if (pid == 0)
  {
    printf("child\n");
  }
  else
  {
    printf("parent\n");
  }
  exit(0);
}
//exec.c
#include "kernel/types.h"
#include "user/user.h"

int main()
{
  char *argv[] = {"echo", "this", "is", "echo", 0};
  exec("echo",argv);
  printf("exec failed\n");
  exit(0);
}
//forkexec.c
#include "kernel/types.h"
#include "user/user.h"

int main()
{
  int pid,status;
  pid=fork();
  if(pid==0){
    char *argv[]={"echo","THIS","IS","ECHO",0};
    exec("echo",argv);
    printf("exec failed\n");
    exit(1);
  }else{
    printf("parent waiting\n");
    wait(&status);
    printf("the child exited with status %d\n",status);
  }
  exit(0);
}
```