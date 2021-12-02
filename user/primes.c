#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int read_first(int p[],int *num)
{
      if(read(p[0],num,sizeof(int))== sizeof(int)){
             printf("prime %d\n",*num) ;
              return 1 ;
      }
      return 0 ;

}

void tansmit(int p1[],int p2[],int num)
{
      int tmp ;
       while(read(p1[0],&tmp,sizeof(int))>0){
               if(tmp % num != 0){
                   write(p2[1],&tmp,sizeof(int)) ;
               }        
       }
       close(p1[0]) ;
       close(p2[1]) ;
}


void prime(int *p)
{
     close(p[1]) ; 

      int p2[2] ;
      pipe(p2) ;
      int first_num ;

      if(read_first(p,&first_num))
      {
          if(fork() == 0)
          {
              prime(p2) ;
          }
          tansmit(p,p2,first_num) ;
          wait(0) ;
      }
      else{
          close(p[0]) ;
          close(p[1]) ;
          exit(0) ;
      }

}


int main(int argc,char *argv[])
{ 
    int p[2];
    pipe(p);

    if(fork() == 0){
                prime(p);
    }
    else{
         close(p[0]);
      for(int i = 2 ; i <= 35 ; i++ )
               write(p[1],&i,sizeof(int));
         close(p[1]);
    }
    close(p[0]) ;
    close(p[1]) ;
    wait(0) ;
    exit(0) ;
}