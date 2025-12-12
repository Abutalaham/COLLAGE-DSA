#include <stdio.h>
#include <stdlib.h>

typedef struct {
   char socialSecurityNumber[15];
   char fullName[50];
   char department[30];
   char jobDesignation[30];
   float salary;
   char phoneNumber[15];
} EmployeeInfo;

// Define the Employee node structure
typedef struct EmployeeNode {
   struct EmployeeNode *llink;
   EmployeeInfo data;
   struct EmployeeNode *rlink;
} EmployeeNode;

// Define the EmployeePointer alias
typedef struct EmployeeNode *EmployeePointer;

EmployeePointer head;

void showMenu() {
  printf("\n1. Create DLL of N Employees (End Insertion)\n");
  printf("2. Display DLL and Count Nodes\n");
  printf("3. Insert at End\n");
  printf("4. Delete at End\n");
  printf("5. Insert at Front\n");
  printf("6. Delete at Front\n");
 
  printf("7. Exit\n");
  printf("Enter your choice: ");
}

int getUserChoice() {
  int choice;
  scanf("%d", &choice);
  return choice;
}

// Function to read data for an employee
EmployeeInfo readEmployeeData() {
   EmployeeInfo newEmployee;

   printf("Enter Social Security Number: ");
   scanf("%14s", newEmployee.socialSecurityNumber);

   printf("Enter Full Name: ");
   scanf(" %[^\n]", newEmployee.fullName);

   printf("Enter Department: ");
   scanf(" %[^\n]", newEmployee.department);

   printf("Enter Job Designation: ");
   scanf(" %[^\n]", newEmployee.jobDesignation);

   printf("Enter Salary: ");
   scanf("%f", &newEmployee.salary);

   printf("Enter Phone Number: ");
   scanf("%14s", newEmployee.phoneNumber);

   return newEmployee;
}

// Function to create a new circular node
EmployeePointer getNode(EmployeeInfo data) {
   // Allocate memory for the new node
   EmployeePointer newNode = (EmployeePointer)malloc(sizeof(EmployeeNode));
   
   if (newNode != NULL) {
       // Initialize the data
       newNode->data = data;
       // Make it circular
       newNode->llink = newNode;
       newNode->rlink = newNode;
   }else{
       printf("Memory allocation failed\n");
       exit(EXIT_FAILURE);
   }
   
   return newNode;
}

void dinsert(EmployeePointer node, EmployeePointer newnode) {
   /* insert newnode to the right of node */
   newnode->llink = node;
   newnode->rlink = node->rlink;
   node->rlink->llink = newnode;
   node->rlink = newnode;
}

void ddelete(EmployeePointer node, EmployeePointer deleted) {
   /* delete from the doubly linked list */
   if (node == deleted)
       printf("Deletion of header node not permitted.\n");
   else {
       deleted->llink->rlink = deleted->rlink;
       deleted->rlink->llink = deleted->llink;
       free(deleted);
   }
}

void displayList(void) {
   EmployeePointer current = head->rlink; // Start from the first node
   printf("\nDoubly Linked List:\n");
   while (current != head) {
       printf("SSN: %s, Name: %s, Dept: %s, Designation: %s, Sal: %.2f, PhNo: %s\n",
              current->data.socialSecurityNumber, current->data.fullName, current->data.department,
              current->data.jobDesignation, current->data.salary, current->data.phoneNumber);
       current = current->rlink; // Move to the next node
   }
}

int countNodes(EmployeePointer head) {
   int count = 0;
   EmployeePointer current = head->rlink; // Start from the first node
   while (current != head) {
       count++;
       current = current->rlink; // Move to the next node
   }
   return count;
}

void processChoice(int choice) {
   int n, i;
   EmployeePointer newEmployeeNode;
   EmployeeInfo newEmployee;

  switch (choice) {
      case 1: {
           printf("Enter the number of employees: ");
           scanf("%d", &n);
           for (i = 0; i < n; i++) {
               newEmployee = readEmployeeData();
               newEmployeeNode = getNode(newEmployee);
               dinsert(head, newEmployeeNode);
           }
       }
       break;
       case 2: {
               displayList();
       }
       break;
       case 3: {
                   newEmployee = readEmployeeData();
                   newEmployeeNode = getNode(newEmployee);
                   dinsert(head->llink, newEmployeeNode);
       }
       break;
       case 4: {
                   ddelete(head, head->rlink);
       }
       break;
       case 5: {
                   newEmployee = readEmployeeData();
                   newEmployeeNode = getNode(newEmployee);
                   dinsert(head, newEmployeeNode);
       }
       break;
       case 6: {
                   ddelete(head, head->llink);
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
   EmployeeInfo temp;
   int choice;
   
   head = getNode(temp);
   
   do {
       showMenu();
       choice = getUserChoice();
       processChoice(choice);
   } while (choice != 7);

   return 0;
}
