#ifndef OO_STACK_H
#define OO_STACK_H

#include "oo_stack_type.h"

typedef struct PrivStack PrivStack;
typedef struct Stack Stack;

struct Stack
{
  StackType (*top)  (Stack* self);
  void      (*pop)  (Stack* self);
  void      (*push) (Stack* self, StackType elem);
  int       (*size) (Stack* self);
  int       (*empty)(Stack* self);

  PrivStack* priv_stack;
};

extern Stack* stack_new();
extern void   stack_delete(Stack* stack);

#endif /* OO_STACK_H */
