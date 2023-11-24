#include <stdio.h>

int main()
{
   int tableSize, row, col;
   printf("Please enter a size for your table(1 - 20): ");
   scanf("%i", &tableSize);
   if(tableSize < 1 || tableSize > 20){
      printf("We can't make a table that size. Sorry!\n");
      printf("We'll use the default size of 10 instead.\n");
      tableSize = 10;
   }
   for (row = 0; row <= tableSize; row++)
   {
      for (col = 0; col <= tableSize; col++)
      {
         if(row == 0){
            printf("%4d", col);
         }
         else if(col == 0)
         {
            printf("%4d", row);
         }
         else{
            printf("%4d", row * col);
         }
      }
      printf("\n");
   }
   printf("\nFinal variable values:\n");
   printf("row = %d\n col == %d\n tableSize == %d\n", row, col, tableSize);
}