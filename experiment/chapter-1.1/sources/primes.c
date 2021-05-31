#include "kernel/types.h"
#include "user/user.h"

void dfs(int lp){
    int x,i;
    if (read(lp,&x,sizeof(x))>0){
        fprintf(1,"prime %d\n",x);
        int p[2],pid;
        pipe(p);
        if ((pid=fork())==0){
            close(p[1]);
            close(lp);
            dfs(p[0]);
        }else if (pid>0){
            close(p[0]);
            while(read(lp,&i,sizeof(i))>0){
                if (i%x!=0)
                    write(p[1],&i,sizeof(i));
            }
            close(p[1]);
            close(lp);
            wait(0);
            exit(0);
        }else{
            fprintf(2,"%d fork() error\n",getpid());
            close(lp);
            close(p[0]);
            close(p[1]);
            exit(1);
        }
    }
    close(lp);
    exit(0);
}

int main() {
    int p[2],pid;
    pipe(p);
    if ((pid=fork())==0){
        close(p[1]);
        dfs(p[0]);
    }else if (pid>0){
        close(p[0]);
        int i,n=35;
        for(i=2;i<=n;i++){
            write(p[1],&i,sizeof(i));
        }
        close(p[1]);
        wait(0);
        exit(0);
    }else{
        fprintf(2,"%d fork() error\n",getpid());
        close(p[0]);
        close(p[1]);
        exit(1);
    }
    exit(0);
}
