#include <stdio.h>

void do_stuff(){
   int local = 12;
   printf("Our local variable has a value of %d\n", local);
   printf("Variable address is %p\n", &local);
}

void do_pointers(){
   int i = 1;
   int *pi = &i;
   int **ppi = &pi;

   printf("i = %d, &i = %p\n", i, &i);
   printf("*pi = %p, &pi = %p\n", pi, &pi);
   printf("*ppi = %p, &ppi = %p\n", ppi, &ppi);
}

int main(){
   int count = 1;
   printf("Starting count at %d\n", count);
   printf("count's address %p\n", &count);
   do_stuff();
   do_pointers();
}