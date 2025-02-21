#include <iostream>

using namespace std;

int a = 1;
char b = 'a';
char c[] = "Aleh";
char* d = c;
double e = 2.14;
short f = 41;
int* g = &a;
double* h = &e;

int main(){
   cout << "size of int: " << sizeof(a) << " \n"
      << "size of char: " << sizeof(b) << " \n"
      << "size of char[]: " << sizeof(c) << " \n"
      << "size of char*: " << sizeof(d) << " \n"
      << "size of double: " << sizeof(e) << " \n"
      << "size of short: " << sizeof(f) << " \n"
      << "size of int*: " << sizeof(g) << " \n"
      << "size of double*: " << sizeof(h) << " \n";
}