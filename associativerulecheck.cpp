#include<stdio.h>
#include<stdlib.h>

unsigned char maj(unsigned char *op, unsigned char x, unsigned char y, unsigned char z){
   *op = (x&y)|(y&z)|(z&x);
    return *op;
}

unsigned char min(unsigned char *op, unsigned char x, unsigned char y, unsigned char z){
   unsigned char temp;
   temp = (x&y)|(y&z)|(z&x);
   *op = temp ^ 0x01;
    return *op;
}

int main(){

  unsigned char x, y, z,u, in;
  unsigned char op;
  unsigned char f11,f1,f2,f22,f3,f33;
    int t=0;
  for(in=0x00; in<=0x0F; in++){
     x = (in & (1<<0))>> 0;
     y = (in & (1<<1))>> 1;
     z = (in & (1<<2))>> 2;
     u = (in & (1<<3))>> 3;
      
//1.To check associative law in MIJ
//     f1=maj(&op, y, u, z);
//      f11=maj(&op,x,u,f1);
//
//     printf("\nu=%x, z=%x, y=%x, x=%x----> %x",u,z,y,x,f11);
//
//      f2=maj(&op, y, u, x);
//      f22=maj(&op,z,u,f2);
//    //  printf("\nu=%x, z=%x, y=%x, x=%x----> %x",u,z,y,x,f22);
//
//      f3=maj(&op, u, x, z);
//      f33=maj(&op,y,u,f3);
//
//      if((f11==f22)&&(f11==f33))
//      {
//          t++;
//      }
//
//  }
//    if(t==16)
//    {
//        printf("equivalent");
//    }
//    else
//        printf("ne");

      
 // }
    
    
//2.To check Associative law in minority gate
    
  
           f1=min(&op, y, u, z);
            f11=min(&op,x,u,f1);
      
       //   printf("\nu=%x, z=%x, y=%x, x=%x----> %x",u,z,y,x,f11);
      
            f2=min(&op, y, u, x);
            f22=min(&op,z,u,f2);
       //    printf("\nu=%x, z=%x, y=%x, x=%x----> %x",u,z,y,x,f22);
      
            f3=min(&op, u, x, z);
            f33=min(&op,y,u,f3);
      
    //    printf("\nu=%x, z=%x, y=%x, x=%x----> %x",u,z,y,x,f33);
      
            if((f11==f22)&&(f11==f33))
            {
                t++;
            }
        }
          if(t==16)
          {
             printf("equivalent\n");
          }
          else
             printf("ne\n");
    
  printf("\n");
   return 0;
}
