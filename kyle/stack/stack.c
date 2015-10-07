#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack {
  StackType* elems;
  int size;
};

StackType pop(Stack* s)
{
    return s->elems[s->size--];
}

StackType top(Stack* s)
{
    return s->elems[s->size];
}

void push(Stack* s, StackType newVal)
{
    s->elems[++s->size] = newVal;
}

int empty(Stack* s)
{
    return !s->size;
}

Stack* newStack()
{
    Stack* stack_p = (Stack*)malloc(sizeof(Stack));
    stack_p->size  = 0;
    stack_p->elems = (StackType*)malloc(sizeof(StackType)*20);
    return stack_p;
}

void freeStack(Stack* s)
{
    free(s->elems);
    free(s);
}
