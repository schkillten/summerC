#include "oo_stack.h"
#include "stdio.h"

#include <sys/time.h>

int main()
{
  /*
  int i;
  Stack* stack = stack_new();

  for (i = 0; i < 100000; i++)
  {
    struct Point p = {i, i+1};
    stack->push(stack, i);
  }

  while (!stack->empty(stack))
  {
    struct Point p = stack->top(stack);
    printf("%i %i\n", p.x, p.y);
    stack->pop(stack);
  }

  stack_delete(stack);
  */

  struct timeval startv, endv;
  gettimeofday(&startv, NULL);

  int i;
  Stack* stack = stack_new();

  for (i = 0; i < 10000000; i++)
    stack->push(stack, i);

  while (!stack->empty(stack))
    stack->pop(stack);

  stack_delete(stack);

  gettimeofday(&endv, NULL);
  printf("%lu\n", endv.tv_usec - startv.tv_usec);
}
