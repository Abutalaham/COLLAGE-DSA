#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char st[MAX];
int top = -1;

void push(char c) { st[++top] = c; }
char pop() { return st[top--]; }

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char inf[MAX], post[MAX], c;
    int i, j = 0;

    printf("Enter infix expression: ");
    gets(inf);

    for (i = 0; inf[i]; i++) {
        c = inf[i];

        if (isalnum(c))
            post[j++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (st[top] != '(')
                post[j++] = pop();
            pop();
        }
        else {
            while (top != -1 && prec(st[top]) >= prec(c))
                post[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        post[j++] = pop();

    post[j] = '\0';
    printf("Postfix: %s\n", post);
    return 0;
}


