#include "kernel/types.h"
#include "kernel/riscv.h"
#include "kernel/sysinfo.h"
#include "user/user.h"

int main(int argc,char *argv[])
{
     struct sysinfo *info = 0 ;
     if(argc < 1 )
          exit(1) ;
      sysinfo(info) ;
     printf("freememroy is %d , USED is %d\n",info->freemem,info->nproc) ;
         exit(0) ;

}