#include <stdio.h>
#include <conio.h>
#define MAX 5

int stack[MAX], top = -1;

void push();
int pop();
void display();
void palin();

int main() {
    int ele, choice;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Palindrome\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2:
                ele = pop();
                if (ele != -1)
                    printf("Element deleted: %d\n", ele);
                break;
            case 3: display(); break;
            case 4: palin(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

void push() {
    int element;
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        printf("Enter element to push: ");
        scanf("%d", &element);
        top++;
        stack[top] = element;
    }
}

int pop() {
    int element;
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        element = stack[top];
        top--;
        return element;
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

void palin() {
    char s[20], st[20];
    int i, flag = 1;
    int temp_top = -1;

    printf("Enter a string: ");
    fflush(stdin);
    gets(st);

    for (i = 0; st[i] != '\0'; i++)
        s[++temp_top] = st[i];

    for (i = 0; st[i] != '\0'; i++) {
        if (st[i] != s[temp_top--]) {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("String is palindrome\n");
    else
        printf("String is not palindrome\n");
}

