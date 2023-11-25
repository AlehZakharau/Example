#include <stdio.h>

void print_details(int number){
   printf("%3d %03o 0x%02X\n", number, number, number);
}

void print_details_C(char c){
   printf("%3c %03o 0x%02X\n", c, c, c);
}

int main(){
   char a = 'a';
   char b = 'e';

   print_details_C(a);
   print_details_C(b);

   char and = a & b;

   print_details_C(and);

   and = a | b;

   print_details_C(and);

   and = ~a;
   print_details_C(and);
   and = ~b;
   print_details_C(and);

   and = a ^ b;

   print_details_C(and);

   and = a << 4;

   print_details_C(and);

   and = b >> 4;

   print_details_C(and);

}

