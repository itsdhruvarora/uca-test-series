// Ques Link: https://leetcode.com/problems/valid-parentheses

#include <stdlib.h>
#include <stdbool.h>

bool isValid(char* s) {
    int st[10000];
    int top = -1;
    
    for (int i = 0; i < strlen(s); i++) {
        if (top == -1) {
            st[++top] = s[i];
        } else if (st[top] == '(' && s[i] == ')') {
            top--;
        } else if (st[top] == '[' && s[i] == ']') {
            top--;
        } else if (st[top] == '{' && s[i] == '}') {
            top--;
        } else {
            st[++top] = s[i];
        }
    }

    return top == -1;
}



