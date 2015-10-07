#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>

#define DEFAULT_SIZE 80

struct Stack
{
  StackType* elems;
  int size;
  int max_size;
};

Stack* stack_new()
{
  Stack* stack    = (Stack*)calloc(1, sizeof(Stack));
  stack->elems    = (StackType*)calloc(DEFAULT_SIZE, sizeof(StackType));
  stack->size     = 0;
  stack->max_size = DEFAULT_SIZE;

  return stack;
}

void stack_delete(Stack* stack)
{
  free(stack->elems);
  stack->elems = NULL;

  free(stack);
  stack = NULL;
}

int stack_top(Stack* stack)
{
  if (stack->size > 0)
    return stack->elems[stack->size - 1];

  fprintf(stderr, "Stack is empty!\n");
  return -1;
}

void stack_pop(Stack* stack)
{
  if (stack->size > 0)
    stack->size--;
}

void stack_push(Stack* stack, StackType elem)
{
  if (stack->size > stack->max_size)
  {
    int new_size    = stack->max_size * 2;
    stack->max_size = new_size;
    stack->elems    = (StackType*)realloc(stack->elems, sizeof(StackType) * new_size);
  }

  stack->elems[stack->size] = elem;
  stack->size++;
}

int stack_size(Stack* stack)
{
  return stack->size;
}

int stack_empty(Stack* stack)
{
  return stack->size == 0;
}

int main()
{
  /*
  Stack* stack = stack_new();
  stack_push(stack, 1);
  stack_push(stack, 2);
  stack_push(stack, 3);
  stack_push(stack, 4);

  printf("SIZE: %i\n", stack_size(stack));

  while (!stack_empty(stack))
  {
    printf("%i\n", stack_top(stack));
    stack_pop(stack);
  }

  stack_delete(stack);
  */

  struct timeval startv, endv;
  gettimeofday(&startv, NULL);

  int i;
  Stack* stack = stack_new();

  for (i = 0; i < 10000000; i++)
    stack_push(stack, i);

  while (!stack_empty(stack))
    stack_pop(stack);

  stack_delete(stack);

  gettimeofday(&endv, NULL);
  printf("%lu\n", endv.tv_usec - startv.tv_usec);

  return 0;
}
