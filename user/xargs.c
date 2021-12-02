#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"


int main(int argc,char *argv[])
{
   char buf[512] ;
   char *Before_argv[MAXARG];
   int argc_num = argc - 1 ;
   if(argc < 2)
   {
       fprintf(2,"please input your command") ;
       exit(1);
   } 
   for(int i = 1 ; i < argc ; i ++ )
   {
       Before_argv[i-1] = argv[i] ; 
   }
   
   int RS = 1 ;
   while(RS == 1){
       int begin = 0 ;
       int i = 0 ;
       while(1){
       RS =  read(0,&buf[i],1) ;
        if(buf[i] == ' ' || buf[i] == '\n' || RS != 1)
        {
            buf[i] = 0 ;
            Before_argv[argc_num++] = &buf[begin] ;
            begin =  i + 1  ; 
        }
        if(RS != 1 || buf[i] == '\n')
        {
            break ;
        }
           i++ ;
       }
        if(fork()==0){
            exec(argv[1],Before_argv);
        }
        wait(0) ;
   }
     exit(0) ;

}