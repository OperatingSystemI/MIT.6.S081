#include "kernel/types.h"
#include "user/user.h"

void dfs(int in)
{
  int p;
  if (read(in, &p, sizeof(int)) <= 0)
  {
    close(in);
    exit(0);
  }
  // printf("%d: %d\n", in, p);
  printf("prime %d\n", p);
  int fd[2];
  pipe(fd);
  if (!fork())
  {
    close(in);
    close(fd[1]);
    dfs(fd[0]);
    exit(0);
  }
  close(fd[0]);
  int n;
  while (read(in, &n, sizeof(int)) > 0) //必须写>0
  {
    if (n % p != 0)
      write(fd[1], &n, sizeof(int));
  }
  //为什么这里要关掉？dfs子进程跟这里有关系吗？因为关联到全局的文件描述符
  close(in);
  close(fd[1]);
  wait(0);
}

int main(int argc, char *argv[])
{
  int fd[2];
  pipe(fd);
  if (!fork())
  {
    close(fd[1]);
    dfs(fd[0]);
    exit(0);
  }
  close(fd[0]);
  int n;
  for (n = 2; n <= 35; n++)
  {
    write(fd[1], &n, sizeof(int));
  }
  close(fd[1]);
  wait(0);

  exit(0);
}
// #include "kernel/types.h"
// #include "user/user.h"

// void close_pipe(int *p)
// {
//   close(p[0]);
//   close(p[1]);
// }

// void primes()
// {
//   int n, p;
//   int fd[2];

//   if (read(0, &p, sizeof(int)) <= 0)
//   {
//     close(1);
//     exit(0);
//   }
//   printf("prime %d\n", p);

//   pipe(fd);
//   if (!fork())
//   {
//     close(0);
//     dup(fd[0]);
//     close_pipe(fd);
//     primes();
//   }

//   close(1);
//   dup(fd[1]);
//   close_pipe(fd);
//   while (read(0, &n, sizeof(int)) > 0)
//   {
//     if (n % p != 0)
//     {
//       write(1, &n, sizeof(int));
//     }
//   }
//   close(1);
//   wait(0);
// }

// int main()
// {
//   int fd[2];

//   pipe(fd);
//   if (!fork())
//   {
//     close(0);
//     dup(fd[0]);
//     close_pipe(fd);
//     primes();
//   }

//   close(1);
//   dup(fd[1]);
//   int n;
//   close_pipe(fd);
//   for (n = 2; n <= 35; n++)
//   {
//     write(1, &n, sizeof(int));
//   }
//   close(1);
//   wait(0);
//   exit(0);
// }
