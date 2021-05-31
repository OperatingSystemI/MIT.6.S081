/**
 * @author mengqiangding
 * @email mengqiangding@icloud.com
 * @create date 2021-05-30 16:00:38
 * @modify date 2021-05-31 19:04:33
 * @desc [description]
 */

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

char* fmtname(char *path){
    char *p = path;
    while (*p != 0) p++;
    while (*p != '/' && p!=path)p--;
    if (*   p == '/')
        return p+1;
    else 
        return path;
}
void find(char *path, char* file_name){
    int fd;
    struct stat st;
    struct dirent de;
    char *p, buf[512];
    if((fd = open(path,0)) < 0){
        fprintf(2,"find: cannot open %s\n",path);
        exit(1);
    }
    //fprintf(1,"open successed!\n");
    if ((fstat(fd, &st)) < 0){
        fprintf(2,"find: cannot open %s\n,path");
    }
    //fprintf(1,"fstat successed!\n");
    switch(st.type){
        case T_FILE:     
            if (strcmp(fmtname(path),file_name) == 0){
                fprintf(1,"%s\n",path);
            }
            break;
        case T_DIR:
            strcpy(buf,path);
            int len = strlen(buf);
            while(read(fd, &de, sizeof(de)) == sizeof(de)){
                if (*de.name=='.' || de.inum==0)
                    continue;
                p = buf + len;
                *p++='/';         
                memmove(p, de.name, DIRSIZ);  
                *(p+DIRSIZ) = 0;
                //fprintf(1,"#%s#%s#%s#\n",path,buf , file_name);
                find(buf, file_name);  
            }
            break;
    }
    close(fd);
    return;
}
int main(int argc, char** argv){
    if (argc<3){
        fprintf(2,"Usage: find <path> <file_name>\n");
        exit(1);
    }
    find(argv[1],argv[2]);
    exit(0);
}
