#include <iostream>
#include <string.h>

using namespace std;
char alpha[] = "abcdefghijklmnopqrstuvwxyz0123456789";

int main(){
   int sz = strlen(alpha);
   for (int i = 0; i < sz; i++)
   {
      char ch = alpha[i];
      cout << "\n "<< ch 
      << ":= " << int(ch)
      << " || 0" << oct << ch 
      << " || x" << hex << ch;
      printf(" || %.2x", ch);
      printf(" || 0%o", ch);
      printf(" || x%X", ch);
      printf(" || %d", ch);
   }
   
   

   return 0;
}