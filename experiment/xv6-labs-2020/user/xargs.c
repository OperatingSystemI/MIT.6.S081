/**
 * @author mengqiangding
 * @email mengqiangding@icloud.com
 * @create date 2021-05-31 19:25:36
 * @modify date 2021-05-31 20:09:48
 * @desc [description]
 */
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"

int main(int argc,char **argv){
    char *params[MAXARG];
    char str[20*MAXARG];
    char buf[MAXARG];
    char end = 0;
    int i;
        
    for(i=0;i<argc;i++)
        params[i] = argv[i];
    int x,len = 0;
    while((x=read(0,str+len,512))>0) len += x;
    x = 0;
    for(int i=0;i<len;i++){
        if (str[i] == '\n' || str[i] ==' '){
            buf[x] = 0;
            params[argc] = buf;
            params[argc+1] = &end;  
            if (fork()==0){
                exec(params[1],params+1);
                exit(0);
            }
            wait(0);
            x = 0;
        }else{
            buf[x++] = str[i];
        }
    }
    exit(0);
}