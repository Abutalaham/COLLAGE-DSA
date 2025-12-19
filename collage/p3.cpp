#include <stdio.h>
#define MAX 5

int st[MAX], top = -1;

void push() {
    int x;
    if (top == MAX - 1)
        printf("Overflow\n");
    else {
        printf("Enter element: ");
        scanf("%d", &x);
        st[++top] = x;
    }
}

int pop() {
    if (top == -1) {
        printf("Underflow\n");
        return -1;
    }
    return st[top--];
}

void display() {
    if (top == -1)
        printf("Stack empty\n");
    else
        for (int i = top; i >= 0; i--)
            printf("%d\n", st[i]);
}

void palin() {
    char s[20], r[20];
    int i, t = -1, f = 1;

    printf("Enter string: ");
    scanf("%s", s);

    for (i = 0; s[i]; i++)
        r[++t] = s[i];

    for (i = 0; s[i]; i++)
        if (s[i] != r[t--]) { f = 0; break; }

    printf(f ? "Palindrome\n" : "Not Palindrome\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Push 2.Pop 3.Display 4.Palindrome 5.Exit\n");
        scanf("%d", &ch);
        if (ch == 1) push();
        else if (ch == 2 && (x = pop()) != -1) printf("Popped: %d\n", x);
        else if (ch == 3) display();
        else if (ch == 4) palin();
        else if (ch == 5) break;
        else printf("Invalid choice\n");
    }
    return 0;
}

