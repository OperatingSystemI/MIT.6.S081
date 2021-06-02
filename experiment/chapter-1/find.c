#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"


void dfs(char *path, char *curFile, char *destFile)
{
  char buf[512], *p;
  int fd;
  struct dirent de;
  struct stat st;
  // printf("path: %s curFile: %s\n", path, curFile);

  fd = open(path, 0);

  fstat(fd, &st);

  switch (st.type)
  {
  case T_FILE:
    if (strcmp(curFile, destFile) == 0)
      printf("%s\n", path);
    break;

  case T_DIR:
    if (strlen(path) + 1 + DIRSIZ + 1 > sizeof buf)
    {
      printf("ls: path too long\n");
      break;
    }
    strcpy(buf, path);
    p = buf + strlen(buf);
    *p++ = '/';
    while (read(fd, &de, sizeof(de)) == sizeof(de))
    {
      if (de.inum == 0 || strcmp(de.name, ".") == 0 || strcmp(de.name, "..") == 0)
        continue;
      memmove(p, de.name, DIRSIZ);
      p[DIRSIZ] = 0;
      if (stat(buf, &st) < 0)
      {
        printf("ls: cannot stat %s\n", buf);
        continue;
      }
      dfs(buf, p, destFile);
    }
    break;
  }
  close(fd);
}

int main(int argc, char *argv[])
{
  dfs(argv[1], argv[1], argv[2]);

  exit(0);
}
