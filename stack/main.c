#include <stdio.h>
#define STACK_MAX_SIZE 20
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
typedef struct Stack_tag
{
    int data[STACK_MAX_SIZE];
    int size;

}Stack_n;
//put new element into stack
void push(Stack_n *stack, const int value)
{
    if (stack->size <= STACK_MAX_SIZE)
    {
        stack->data[stack->size] = value;
        stack->size++;
    }
    else exit(STACK_OVERFLOW);
}
//give element from stack
int pop(Stack_n *stack)
{
    if (stack->size >= 0)
    {
        stack->size--;
        return stack->data[stack->size];
    }
    else  exit(STACK_UNDERFLOW);
}
//print element
void printStackValue(const int value)
{
    printf("%d", value);
}
//print size of stack, elements of stack
void printStack(const Stack_n *stack, void (*printStackValue)(const int))
{
    int i;
    int len = stack->size - 1;
    printf("stack %d ", stack->size);
    for (i = 0; i < len; i++)
    {
        printStackValue(stack->data[i]);
        printf(" | ");
    }
    if (stack->size != 0)
    {
        printStackValue(stack->data[i]);
    }
    printf("\n");
}
void add(Stack_n *stack)
{
    push(stack,pop(stack)+pop(stack));
}
void sub(Stack_n *stack)
{
    push(stack,pop(stack)+pop(stack));
}



