// Aim: To implement a C program that performs all basic operations  on a single linked list: insertion at beginning, end, specific position,and displaying the linked list.
ALGORITHM:
1. Algorithm for Insertion at Beginning
 Start
 Create a new node
 Assign data to the new node
 Set new node’s next pointer to current head
 Update head to the new node
 Stop
2. Algorithm for Insertion at End
 Start
 Create a new node
 If list is empty, head = new node
 Else traverse to last node
 Set last node’s next to new node
 Stop
3. Algorithm for Insertion at Position
 Start
 If position = 1, insert at beginning
 Traverse list to reach (position - 1)th node
 Insert new node after this node
 Stop
4. Algorithm for Deletion by Value
 Start
 If list is empty, print message
 If head contains value, delete head
 Else traverse until node before the node to be deleted
 Remove node by adjusting links
 Free memory
 Stop
5. Algorithm for Display
 Traverse from head to end
 Print each node’s data
 Stop
//program:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Insert at beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at a specific position
void insertAtPosition(struct Node** head, int value, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    int k = 1;
    while (temp != NULL && k < pos - 1) {
        temp = temp->next;
        k++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display list
void printList(struct Node* head) {
    printf("List: ");
    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;

            case 4:
                printList(head);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;

}
