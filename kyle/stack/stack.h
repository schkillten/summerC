typedef int StackType;
typedef struct Stack Stack;

StackType pop(Stack* s);
StackType top(Stack* s);
void push(Stack* s, StackType newVal);
int empty(Stack* s);
Stack* newStack();
void freeStack(Stack* s);
