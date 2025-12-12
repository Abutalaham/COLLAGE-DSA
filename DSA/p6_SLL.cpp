#include <stdio.h>
#include <stdlib.h>

// Define the StudentInfo structure
typedef struct {
   char usn[15];
   char name[50];
   char programme[50];
   int sem;
   char phno[15];
} StudentInfo;

// Define the Student node structure
typedef struct StudentNode{
   StudentInfo data;
   struct StudentNode *next;
} StudentNode;


// Define the StudentPointer alias
typedef struct StudentNode *StudentPointer;

StudentPointer first;

void showMenu() {
   printf("\n****** Menu ******\n");  
   printf("\n1. Insert N Studs at Front\n");
   printf("2. Insert at Front\n");
   printf("3. Insert at End\n");
   printf("4. Delete from Front\n");
   printf("5. Delete from End\n");
   printf("6. Display\n");
   
   printf("7. Exit\n");
   printf("\nEnter your choice: ");
}

int getUserChoice() {
  int choice;
  scanf("%d", &choice);
  return choice;
}

// Function to read data for a student
StudentInfo readStudentData() {
   StudentInfo newStudent;

   printf("Enter USN: ");
   scanf("%14s", newStudent.usn);

   printf("Enter Name: ");
   scanf(" %[^\n]", newStudent.name);

   printf("Enter Programme: ");
   scanf(" %[^\n]", newStudent.programme);

   printf("Enter Semester: ");
   scanf("%d", &newStudent.sem);

   printf("Enter Phone Number: ");
   scanf("%14s", newStudent.phno);

   return newStudent;
}

// Function to create a new node
StudentPointer getNode(StudentInfo data) {
   // Allocate memory for the new node
   StudentPointer newNode = (StudentPointer)malloc(sizeof(StudentNode));
   
    if (newNode == NULL) {
       printf("Memory allocation failed!\n");
       exit(1); // Exit the program if memory allocation fails
   }
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

// Function to insert a node at the front  
void insertFront(StudentPointer newNode) {  
   newNode->next = first;  
   first = newNode;  
}  

// Function to insert a node at the end  
void insertEnd(StudentPointer newNode) {  
   
   if (first == NULL) {  
       first = newNode;  
       return;  
   }  
 
   StudentPointer last = first;  
   while (last->next != NULL) {  
       last = last->next;  
   }  
 
   last->next = newNode;  
}  

// Function to delete a node from the front  
void deleteFront() {  
   if (first == NULL) {  
       printf("List is empty, can not delete.\n");  
       return;  
   }  
 
   StudentPointer tempNode = first;  
   first = first->next;  
   free(tempNode);  
}  

// Function to delete a node from the end  
void deleteEnd() {  
   if (first == NULL) {  
       printf("List is empty, can not delete.\n");  
       return;  
   }  
   
   if (first->next == NULL) {  
       free(first);  
       first = NULL;  
       return;  
   }  

   StudentPointer second_last = first;  
   while (second_last->next->next != NULL) {  
       second_last = second_last->next;  
   }  
 
   free(second_last->next);  
   second_last->next = NULL;  
}  

// Function to count the number of nodes  
int countNodes(void) {  
   int count = 0;  
   StudentPointer current = first;  
   while (current != NULL) {  
       count++;  
       current = current->next;  
   }  
   return count;  
}  

// Function to display the list  
void display() {  
   StudentPointer ptr = first;  
   while (ptr) {  
       printf("USN: %s, Name: %s, Programme: %s, Semester: %d, Phone No: %s\n", ptr->data.usn, ptr->data.name, ptr->data.programme, ptr->data.sem, ptr->data.phno);  
       ptr = ptr->next;  
   }  
   printf("Total nodes: %d\n", countNodes());  
}  

void processChoice(int choice) {
   int n, i;
   StudentInfo newStudent;
   StudentPointer newStudentNode;

  switch (choice) {
      case 1: {
           printf("Enter the number of students: ");
           scanf("%d", &n);
           for (i = 0; i < n; i++) {
               newStudent = readStudentData();
               newStudentNode = getNode(newStudent);
               insertFront(newStudentNode);
           }
       }
       break;
       case 2: {
           newStudent = readStudentData();
           newStudentNode = getNode(newStudent);
           insertFront(newStudentNode);
       }
       break;
       case 3: {
           newStudent = readStudentData();
           newStudentNode = getNode(newStudent);
           insertEnd(newStudentNode);
       }
       break;
       case 4: {
           deleteFront();
       }
       break;
       case 5: {
           deleteEnd();
       }
       break;
       case 6: {
           display();
       }
       break;
       case 7:
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
   } while (choice != 7);

   return 0;
}


