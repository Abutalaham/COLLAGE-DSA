#include    <stdio.h>
#include    <stdlib.h>

#define MAX_QUEUE_SIZE 5

char queue[MAX_QUEUE_SIZE];
int front = 0, rear = 0;


void showMenu() {
   printf("\nMenu:\n");
   printf("1. Insert an Element\n");
   printf("2. Delete an Element\n");
   printf("3. Demonstrate Overflow\n");
   printf("4. Demonstrate Underflow\n");
   printf("5. Display the status\n");
   
   printf("6. Exit\n");
   printf("Enter your choice: ");
}

int getUserChoice() {
  int choice;
  scanf("%d", &choice);
  return choice;
}

void queueFull() {
   printf("Queue is full. Overflow occurred.\n");
   
   if(front == 0){
       rear = MAX_QUEUE_SIZE - 1;
   } else{
       rear = front - 1;
   }
}

char queueEmpty() {
   printf("Queue is empty. Underflow occurred.\n");
        
   return '\0'; 
}

void addq(char item) {
   rear = (rear + 1) % MAX_QUEUE_SIZE;

   if (front == rear) {
       queueFull();
       return;
   }
   
   queue[rear] = item;
}

char deleteq() {
   if (front == rear) {
       return queueEmpty();
   }
   front = (front + 1) % MAX_QUEUE_SIZE;
   return queue[front];
}

void displayStatus() {
   printf("Current Queue status: ");
   if (front == rear) {
       printf("Empty\n");
   } else {
       int i;
       for (i = (front + 1) % MAX_QUEUE_SIZE; i != rear; i = (i + 1) % MAX_QUEUE_SIZE) {
           printf("%c ", queue[i]);
       }
       printf("%c\n", queue[i]);
   }
}

void processChoice(int choice) {
   char item;
   
   getchar();
   
   switch (choice) {
      case 1: {
           printf("Enter the element to insert: ");
           item = getchar();
           addq(item);
       }
       break;
       case 2: {
           item = deleteq();
           if (item != '\0') {
               printf("Deleted element: %c\n", item);
           }
       }
       break;
       case 3: {
           printf("Demonstrating Overflow...\n");
           for (char ch = 'A'; ch <= 'F'; ch++) {
               addq(ch);
           }
           displayStatus();
       }
       break;
       case 4: {
           printf("Demonstrating Underflow...\n");
           for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
               deleteq();
           }
           displayStatus();
       }
       break;
       case 5: {
           printf("Displaying the status of Circular QUEUE:\n");
           displayStatus();
       }
       break;
       case 6:
          printf("Exiting...\n");
          break;
       default:
          printf("Invalid choice!\n");
  }
}

int main() {
   int choice;
   
   do {
       showMenu();
       choice = getUserChoice();
       processChoice(choice);
   } while (choice != 6);

   return 0;
}
