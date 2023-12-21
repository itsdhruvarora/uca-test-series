#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    /* data */
    int arr[1000];
    int top;
};

void initialize(struct Stack *stack){
    stack->top = -1;
}

int isEmpty(struct Stack *stack){
    return stack->top == -1;
}

int isFull(struct Stack *stack){
    return stack->top == 999;
}
void push(struct Stack *stack, int val){
    if(isFull(stack)){
        printf("stack overflow");
        return;
    }

    stack->arr[++stack->top] = val;
}

int pop(struct Stack *stack){
    if(isEmpty(stack)){
        printf("stack underflow");
        return -1;
    }

    return stack->arr[stack->top--];
}

int peek(struct Stack *stack){
    if(isEmpty(stack)){
        return -1;
    }

    return stack->arr[stack->top];
}

int main(){
    struct Stack myStack;
    initialize(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element: %d\n", peek(&myStack));

    printf("Popped element: %d\n", pop(&myStack));
    printf("Popped element: %d\n", pop(&myStack));

    printf("Is the stack empty? %s\n", isEmpty(&myStack) ? "Yes" : "No");

}


