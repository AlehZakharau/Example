#include <stdio.h>

int main() {
   int a, b;

   printf("Enter first number: ");
   scanf("%i", &a);
   printf("\nEnter second number:");
   scanf("%i", &b);

   while ( b > 0){
      if (a > b)
         a = a - b;
      else
         b = b - a;
      
      printf("\n%i", a);
   }
}