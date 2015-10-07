#include "oo_stack.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define DEFAULT_SIZE 80

struct PrivStack
{
  StackType* elems;
  int size;
  int max_size;
};

static StackType priv_top(Stack* self)
{
  int size = self->priv_stack->size;

  if (size <= 0)
    fprintf(stderr, "Nothing in the stack!\n");

  return self->priv_stack->elems[size - 1];
}

static void priv_pop(Stack* self)
{
  if (self->priv_stack->size > 0)
    self->priv_stack->size--;
  else
    fprintf(stderr, "Nothing left in the stack! Stop!\n");
}

static void priv_double_stack_size(Stack* self)
{
  int max_size               = self->priv_stack->max_size;
  int new_size               = max_size * 2;
  self->priv_stack->max_size = new_size;
  self->priv_stack->elems    = (StackType*)realloc(self->priv_stack->elems,
                                                   sizeof(StackType) * new_size);
}

static void priv_push(Stack* self, StackType elem)
{
  int size     = self->priv_stack->size;
  int max_size = self->priv_stack->max_size;

  /* double space */
  if (size > max_size)
    priv_double_stack_size(self);

  self->priv_stack->elems[size] = elem;
  self->priv_stack->size++;
}

static int priv_size(Stack* self)
{
  return self->priv_stack->size;
}

static int priv_empty(Stack* self)
{
  return self->priv_stack->size == 0;
}

Stack* stack_new()
{
  Stack*     stack;
  PrivStack* priv_stack;

  priv_stack           = (PrivStack*)calloc(1, sizeof(PrivStack));
  priv_stack->elems    = (StackType*)calloc(DEFAULT_SIZE, sizeof(StackType));
  priv_stack->size     = 0;
  priv_stack->max_size = DEFAULT_SIZE;

  stack             = (Stack*)calloc(1, sizeof(Stack));
  stack->top        = &priv_top;
  stack->pop        = &priv_pop;
  stack->push       = &priv_push;
  stack->size       = &priv_size;
  stack->empty      = &priv_empty;
  stack->priv_stack = priv_stack;

  return stack;
}

void stack_delete(Stack* stack)
{
  free(stack->priv_stack->elems);
  free(stack->priv_stack);
  free(stack);
}
