#include <stdio.h>
#include <assert.h>

void sort_charts(int n, unsigned char array[n]){
   int buckets[256];
   for (int i = 0; i < n; i++)
   {
      unsigned int bucket = array[i];
      buckets[bucket]++;
   }

   int k = 0;
   for (int i = 0; i < 256; i++){
      for (int j = 0; j < buckets[i]; j++){
         array[k++] = (unsigned char)i;
      }
   }
}

void compute_buckets(int n, char *array[n], int buckets[256]){
   for (int i = 0; i < 256; i++){
      buckets[i] = 0;
   }
   for (int i = 0; i < n; i++){
      unsigned char bucket = (unsigned char)array[i][0];
      buckets[bucket]++;
   }
   int m = n;
   for (int i = 256 - 1; i > 0; i--){
      int count = buckets[i];
      buckets[i] = m - count;
      //printf("bucket == %d, m = %d, count = %d\n", buckets[i], m, count);
      m -= count;
   }
}

void sort_strings(int n, char *input[n], char *output[n]){
   int buckets[256];
   compute_buckets(n, input, buckets);
   for (int i = 0; i < n; i++){
      unsigned char bucket = (unsigned char)input[i][0];
      int index = buckets[bucket]++;
      output[index] = input[i];
   }
}

int *scan_right(int *left, int *right){
   while(left < right){
      if(*left >= 0) break;
      left++;
   }
   return left;
}

int *scan_left(int *left, int *right){
   while (left < right){
      if(right < 0) break;
      right--;
   }
   return right;
}

void swap(int *left, int *right){
   int i = *left;
   *left = *right;
   *right = i;
}

int split(int n, int array[n]){
   int *left = array, *right = array + n - 1;
   while (left < right){
      left = scan_right(left, right);
      right = scan_left(left, right);
      swap(left, right);
   }
   return left - array;
}

void reverse(int n, int array[n]){
   int *left = array, *right = array + n - 1;
   while (left < right){
      swap(left++, right--);
   }
}

void bucket_sort(int n, int offset, int const input[n], int output[n]){
   int buckets[256];
   for (int i = 0; i < 256; i++){
      buckets[i] = 0;
   }
   for (int i = 0; i < n; i++){
      unsigned char bucket = (input[i] >> 8 * offset) & 0xff;
      buckets[bucket]++;
   }
   int m = n;
   for (int i = 256 - 1; i >= 0; i--){
      int count = buckets[i];
      buckets[i] = m - count;
      m-= count;
   }
   for (int i = 0; i < n; i++){
      unsigned char bucket = (input[i] >> 8 * offset) & 0xff;
      int index = buckets[bucket]++;
      output[index] = input[i];
   }
}

void radix_sort(int n, int array[n]){
   static_assert(sizeof *array % 2 == 0, "integer sizes must be powers of two");
   int helper[n];
   int *buffers[] = {array, helper};
   int bucket_input = 0;

   for (int offset = 0; offset < sizeof *array; offset++){
      bucket_sort(n, offset, buffers[bucket_input], buffers[!bucket_input]);
      bucket_input = !bucket_input;
   }
}

void sort_int(int n, int array[n]){
   if(n <= 0) return;
   int m = split(n, array);
   printf("m == %d\n", m);
   for (int i = 0; i < n; i++){
      printf("%d ", array[i]);
   }
   printf("\n");
   if(m > 0){
      radix_sort(m, array);
      reverse(m, array);
   }
   if(m < n){
      radix_sort(n - m, array + m);
   }
}

int main(){
   unsigned char array[] = { 'f', 'o', 'o', 'b', 'a', 'r' };
   char *array1[] = {"foo", "boo", "bar", "qoo", "qar", "baz", "qux", "qar", "123"};
   int array2[] = { -1, -2, 13, -2, 13, 6, 14, -3, 42, 13, 23 };
   int n = sizeof array1 / sizeof *array1;
   int n1 = sizeof array2 / sizeof *array2;


   char *output[n];
   //sort_charts(n, array);
   sort_strings(n, array1, output);
   for (int i = 0; i < n; i++){
      printf("%s\n", output[i]);
   }
   radix_sort(n1, array2);
   sort_int(n1, array2);
   for (int i = 0; i < n1; i++){
      printf("%d ", array2[i]);
   }
   printf("\n");
   

   return 0;
}