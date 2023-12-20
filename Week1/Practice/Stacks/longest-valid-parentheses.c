int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestValidParentheses(char* s) {
    int stack[100000] = {-1};
    int top = 0;
    int longest = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stack[top++] = i;
        } else {
            if (top != 0) {
                if (s[stack[top - 1]] == '(') {
                    top--;
                } else {
                    stack[top++] = i;
                }
            } else {
                stack[top++] = i;
            }
        }
    }
    if (top == 0) {
        return strlen(s);
    }

    top--;
    int a = strlen(s);
    int b;

    while (top != -1) {
        b = stack[top];
        top--;
        longest = max(longest, a - b - 1);
        a = b;
    }

    return max(longest, a);
}
