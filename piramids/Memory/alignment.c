#include <stdio.h>
#include <stdalign.h>

int main(){

   printf("char align at %zu and have size of %zu\n", 
      alignof(char), sizeof(char));
   printf("int align at %zu and have size of %zu\n", 
      alignof(int), sizeof(int));
   printf("double align at %zu and have size of %zu\n", 
      alignof(double), sizeof(double));

   return 0;
}