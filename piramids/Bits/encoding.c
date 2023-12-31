#include <stdio.h>

int main(){
   unsigned char source[9] = { 0xd8,0xff,0xe0,0xff,0x10, 0x00, 0x46,0x4a, 0x46 };
   char buffer[4] = {0, 0, 0, 0};

   int source_length = sizeof(source);
   for (int i = 0; i < source_length; i++)
   {
      printf("0x%02x ", source[i]);
   }
   
   printf("==> ");

   for (int i = 0; i < 9; i+= 3)
   {
      unsigned char byte1 = source[i];
      unsigned char byte2 = source[i + 1];
      unsigned char byte3 = source[i + 2];

      buffer[0] = byte1 >> 2;
      buffer[1] = (byte1 & 0x03) << 4;
      buffer[1] |= (byte2 & 0xf0) >> 4;

      buffer[2] = (byte2 & 0x0f) << 2;
      buffer[2] |= (byte3 & 0xc0) >> 6;

      buffer[3] = byte3 & 0x3f;

      for (int i = 0; i < 4; i++)
      {
         if(buffer[i] < 26){
            // value 0 - 24, so upprcase letter
            printf("%c", 'A' + buffer[i]);
         }
         else if(buffer[i] < 52){
            // value 26 - 51, so lowercase letter
            printf("%c", 'a' + (buffer[i] - 26));
         }
         else if(buffer[i] < 62){
            //value 52 - 61, so a digit
            printf("%c", '0' + (buffer[i] - 52));
         }
         else if(buffer[i] == 62){
            // our "+" case, no need for math, just print it
            printf("+");
         }
         else if(buffer[i] == 63){
            // our "/ case, no need for math, just print it"
            printf("/");
         }
         else{
            //Yikes! Error. We should never get here.
            printf("\n\n Error! Bad 6 bit value: %c\n", buffer[i]);
         }
      }
      
   }
   
}