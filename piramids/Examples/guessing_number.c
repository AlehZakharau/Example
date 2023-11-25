#include <stdio.h>

int main(){
   int secretNumber = 42;
   int number = 0;

   while( secretNumber != number){
      printf("Guess a number between 1 and 50: ");
      scanf("%i", &number);
      if( number < 1 || number > 50)
         printf("You need to choose number between 1 and 50\n");

      if(number < secretNumber)
         printf("Too low, try again.\n");

      if(number > secretNumber)
         printf("Too high, try again.\n");
   }

   printf("***Congratulation you got it right!***\n");
}