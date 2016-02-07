#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


char output[256];//initially with all zeroes
int fp;



int main() {
  int max = 255;
  fp = open("pic.ppm", O_CREAT | O_WRONLY,0777);
  sprintf(output , "P3 %i %i %i ", 500,500,max);
  write(fp,output, 255);

  //write(fp , output, 256);
  //now the mathy stuff
  int pixelNo=0;
  int r =3;
  int g = 255;
  int b = 17;
  while (pixelNo< 250000) {//should make 500^2 pixels
     r= (r+1 ) % 255;
    g = ((g - 1) ) %255;//(g*g) % 255;
    b = (r* 11 ) % 255;
    pixelNo ++;
    sprintf(output, " %d %d %d ", r , g ,b );
    
    printf("%d %d %d\n", r , g ,b );

    write(fp , output, 255);
 }
  close(fp);
 return  0 ;
}
