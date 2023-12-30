https://www.hackerrank.com/contests/17cs1102/challenges/8-c-postfix-expression-evaluation

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int top;
    int size;
    int *arr;
} Stack;

Stack* createStack(int size) {
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->top = -1;
    stk->size = size;
    stk->arr = (int*)malloc(size * sizeof(int));
    return stk;
}

bool isEmpty(Stack* stk) {
    return stk->top == -1;
}

int peek(Stack* stk) {
    if (isEmpty(stk)) return 0;
    return stk->arr[stk->top];
}

int pop(Stack* stk) {
    if (!isEmpty(stk)) {
        return stk->arr[stk->top--];
    }
    return -1; // Indicate an error (stack underflow)
}

void push(Stack* stk, int item) {
    stk->arr[++stk->top] = item;
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int performOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
    }
    return 0;
}

int evaluateExpression(char* s) {
    int len = strlen(s);
    Stack* stack = createStack(1000);
 // printf("%d", len);
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
           
            int x = 0;
            while (isDigit(s[i]) && i < len) {
                x = x * 10 + (s[i] - '0');
                i++;
            }
            push(stack, x);
            i--;
        }

        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            int y = pop(stack);
            int x = pop(stack);

            int eval = performOperation(x, y, s[i]);
            push(stack, eval);
        }
    }

    return peek(stack);
}

int main() {
    int n;
    scanf("%d", &n);
    
    while(n--){
        char str[10000];
        scanf(" %[^\n]", str);
        int result = evaluateExpression(str);
        printf("%d\n", result);
    }

    return 0;
}
