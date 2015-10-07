#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;
typedef int StackType;

extern Stack* stack_new();
extern void   stack_delete(Stack* stack);

extern StackType stack_top  (Stack* stack);
extern void      stack_pop  (Stack* stack);
extern void      stack_push (Stack* stack, StackType elem);
extern int       stack_size (Stack* stack);
extern int       stack_empty(Stack* stack);

#endif /* STACK_H */
