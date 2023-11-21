#include <stdio.h>

int main()
{
   int length;

   printf("Enter number from 1 to 20 \n");
   scanf("%d", &length);

   length = (int)length;
   int n = length - 1;

   if(length > 20 || length < 1){
      printf("Wrong input");
      return 0;
   }

   for(int i = 0; i < length; i++){
      for(int j = 0; j < length - n; j++){
         printf("*");
      }
      printf("\n");
      n--;
   }

}