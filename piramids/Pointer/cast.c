#include <stdio.h>


void ind_bytes(){
   int a[] = { 1, 2, 3, 4, 5 };
   int n = sizeof a / sizeof *a;

   for (int i = 0; i < n; i++){
      printf("%d = [", a[i]);
      char *cp = (char *)(a + i);
      for(int j = 0; j < sizeof *a; j++){
         printf(" %d ", cp[j]);
      }
      printf("]\n");
   }
}

int f(int *i, long *l){
   *i = -1;
   *l = 0;
   return *i;
}

int g (char *c, long *l){
   *c = -1;
   *l = 0;
   return *c;
}


int main(){

   ind_bytes();

   long x = 1;
   int i = f((int *)&x, &x);
   int j = g((char *)&x, &x);
   printf("%ld %d %d\n", x, i, j);
   return 0;
}