#include <stdio.h>
#include <assert.h>

void check_size(){
   int array[] = { 1, 2, 3, 4, 5 };
   int *ap = array;
   printf("sizeof array == %zu, sizeof ap == %zu\n",
      sizeof array, sizeof ap);
   printf("%p %p %p %p\n", array, &array, ap, &ap);
   int n = sizeof array / sizeof *array;
   for (int i = 0; i < n; i++)
   {
      assert(array[i] == ap[i]);
      assert(array + i == ap + i);
      assert(*(array + i) == *(ap + i));
   }
}


int *bin_search( int *left, int *right, int x){
   while (left < right)
   {
      int *mid = (right - left)/2 + left;
      if(*mid == x) return mid;
      if(*mid < x){
         left = mid + 1;
      }
      else{
         right = mid;
      }
   }
   return 0;
}

void test_bin_search(){
   int a[] = { 1, 2, 4, 5, 23};
   int n = sizeof a / sizeof *a;
   int *res = bin_search(a, a + n, 5);
   printf("Result == %d\n", *res);
   printf("ar %p, %p", &a[3], &*res);
}

void swap_array(int array[], int i, int j){
   int temp = array[j];
   array[j] = array[i];
   array[i] = temp;
}

void reverse_array(int n , int array[n]){
   for (int i = 0; i < n/2; i++) {
      swap_array(array, i, n - i - 1);
   }
}

void swap_pointers(int *i, int *j){
   int temp = *i;
   *i = *j;
   *j = temp;
}

void reverse_pointers(int *begin, int *end){
   if( end <= begin) return;
   end--;
   while (begin < end)  {
      swap_pointers(begin++, end--);
   }
}

int compact0(int n, int array[n]){
   int m = 0;
   for(int i = 0; i < n; i++){
      if(array[i] > 0)
         array[m++] = array[i];
   }
   return m;
}

int eratosphenes(int n, int buf[n - 2]){
   //Init
   for (int i = 2; i < n; i++)
   {
      buf[i - 2] = i;
   }

   //Sieve
   for(int i = 0; i*i < n - 2; i++){
      if(buf[i] == 0) continue;
      int p = buf[i];
      for (int j = p*p; j < n; j += p){
         buf[j - 2] = 0;
      }
   }  
      
   //Compact
   return compact0(n -2, buf);
}

void sieve_candidates(int **from, int **to, int p){
   int *output = *from;
   for (int *input = *from; input < *to; input++){
      if(*input % p != 0)
         *output++ = *input;
   }
   *to = output;
}

int pointer_eratosphenes(int n, int buf[n - 2]){
   //Init
   for (int i = 2; i < n; i++)
   {
      buf[i - 2] = i;
   }

   //Sieve
   int *candidates = buf;
   int *end = buf + n -2;
   while (candidates < end)
   {
      int p = *candidates++;
      sieve_candidates(&candidates, &end, p);
   }
   
      
   //Compact
   return end - buf;
}

void test_eratosphenes(){
   int array[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
   int array1[] = {2, 3, 4};
   int array2[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
   int n = sizeof array / sizeof *array;
   int n1 = sizeof array1 / sizeof *array1;
   int n2 = sizeof array2 / sizeof *array2;
   int res = eratosphenes(n, array);
   int res1 = eratosphenes(n1, array1);
   int res2 = eratosphenes(n2, array2);
   
   printf("Result == %d, %d, %d\n", res, res1, res2);
}

int main(){
   test_eratosphenes();
   test_bin_search();
   return 0;
}