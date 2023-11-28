#include <stdio.h>

void do_stuff(){
   int local = 12;
   printf("Our local variable has a value of %d\n", local);
   printf("Variable address is %p\n", &local);
}

int main(){
   int count = 1;
   printf("Starting count at %d\n", count);
   printf("count's address %p\n", &count);
   do_stuff();
   do_stuff();
}