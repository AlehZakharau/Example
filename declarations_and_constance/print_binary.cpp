#include <stdio.h>
#include <iostream>


void printBinaryWithPadding(int num){
   for (int i = sizeof(int) * 8 -1; i >= 0; i--)
   {
      printf("%d", (num >> i) & 1);
      if (i % 4 == 0) printf(" ");
   }
   printf("\n");
}

int main(){
   int number = 0;
   std::cout << "Print any number: ";
   std::cin >> number;
   printf("Binary representation of %d: ", number);
   printBinaryWithPadding(number);
   return 0;
}