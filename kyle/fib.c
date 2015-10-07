#include <stdio.h>
#include <sys/time.h>


int main()
{
  int test_val = 100000;
  struct timeval startv;
  struct timeval endv;
  if (gettimeofday(&startv, NULL)){
    printf("gettimeofday failed");
    return -1;
  }
  int v = fibStart(test_val);
  if (gettimeofday(&endv, NULL)){
    printf("gettimeofday failed");
    return -1;
  }
  long dur = endv.tv_usec - startv.tv_usec;
  printf("Dynamic Recursive -\nTime: %lu\nValue: %d\n\n", dur, v);


  struct timeval startIt;
  struct timeval endIt;
  if (gettimeofday(&startIt, NULL)){
    printf("gettimeofday failed");
    return -1;
  }
  int v2 = fibIter(test_val);
  if (gettimeofday(&endIt, NULL)){
    printf("gettimeofday failed");
    return -1;
  }
  long dur2 = endIt.tv_usec - startIt.tv_usec;
  printf("Iterator -\nTime: %lu\nValue: %d\n\n", dur2, v2);
}

int fibStart(int n)
{
  int vals[n];
  int i;
  for(i=0; i<n; i++){
    vals[i] = 0;
  }
  return fib(n, vals);
}


int fib(int n, int *vals)
{
  if (n<2)
  {
    return n;
  }
  else
  {
    if(!vals[n-1]){
      vals[n-1] = fib(n-1, vals);
    }
    if(!vals[n-2]){
      vals[n-2] = fib(n-2, vals);
    }
    return vals[n-1] + vals[n-2];
  }
}

int fibIter(int n)
{
  int a = 0;
  int b = 1;
  int temp, i;
  while(n--){
    temp = b;
    b = a + b;
    a = temp;
  }
  return a;
}
