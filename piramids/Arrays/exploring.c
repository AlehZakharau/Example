#include <stdio.h>

int *ar(int *a, int **b){
   printf("Fun %p, %p\n", &a, &*b);
   int *d = *b;
   return a;
}

int main(){
   int a = 2;
   int *b = &a;

   printf("INT %p, %p\n", &a, &*b);
   int *c = ar(b, &b);
   printf("OUT %d, %p, %p\n", *c, &c, &*b);
   return 0;
}