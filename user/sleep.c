#include "kernel/types.h"
#include "user/user.h"

int main(int argc,char const *argv[])
{
     if (argc != 2 || atoi(argv[1]) <= 0)
     {
         printf("error\n") ;
         exit(1) ;
     }
     sleep(atoi(argv[1]));
     exit(0) ;
    

}