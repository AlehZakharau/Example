#include <stdio.h>


void foo(int const *clip){
   int *ip = (int *)clip;
   *ip = 5;
}

int main(){

   int const i = 42;
   int *p = 0;
   int const **q = 0;
   int j = 12;
   int *ip = (int *)&i;
   *ip = 13;
   printf("i == %d, *ip == %d\n", i, *ip);

   foo(&i);
   foo(&j);
   printf("i == %d, j == %d\n", i, j);

   q = (int const **)&p;
   *q = &i;

   printf("&i == %p, *p == %p\n", (void *)&i, (void *)p);

   *p = 5; //Danger: We are trying to change const int

   printf("i == %d / %d\n", i, *p);

   return 0;
}