#include "kernel/types.h"
#include "user/user.h"

int main(int argc,char *argv[])
{
   char Str = 'A' ;
   int p1[2];
   int p2[2];
   pipe(p1) ; 
   pipe(p2) ;
   int pid = fork() ;
   if(pid == 0)
   {
 
        close(p1[1]) ;
        close(p2[0]) ;
        if(read(p1[0],&Str,sizeof(char)) != sizeof(char))
        {
            fprintf(2,"error");
        } 
        else{
            fprintf(1, "%d: received ping\n", getpid());
        }
         if(write(p2[1],&Str,sizeof(Str)) != sizeof(Str))
        {

            fprintf(2,"error");
        }
        close(p2[1]) ;
        close(p1[0]) ;
        exit(0) ;
   }
   else
   { 
        close(p2[1]) ;
        close(p1[0]) ;
        if(write(p1[1],&Str,sizeof(char))!= sizeof(char) ) 
        {
             fprintf(2,"error");
        }
        if(read(p2[0],&Str,sizeof(char)) != sizeof(char))
        {
            fprintf(2,"error");
        }
        else{
           fprintf(1, "%d: received pong\n", getpid());
        }
        close(p1[1]) ;
        close(p2[0]) ;
        exit(0) ;
   }

}
