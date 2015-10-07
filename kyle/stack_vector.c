#include "stack.h"
#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
  Vector* elems;
};

Stack* stack_new()
{
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->elems = vector_new(0);
}

void stack_delete(Stack* stack)
{
  free(stack->elems);
  free(stack);

  stack->elems = NULL;
  stack        = NULL;
}

int stack_top(Stack* stack)
{
  return vector_back(stack->elems);
}

void stack_pop(Stack* stack)
{
  vector_pop_back(stack->elems);
}

void stack_push(Stack* stack, int elem)
{
  vector_push_back(stack->elems, elem);
}

int stack_size(Stack* stack)
{
  return vector_size(stack->elems);
}

int stack_empty(Stack* stack)
{
  return vector_empty(stack->elems);
}

int main()
{
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
}
