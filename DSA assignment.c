#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node in the middle of the list
void insertMiddle(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    struct Node* slow = *head_ref;
    struct Node* fast = *head_ref;

    // If the list is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    // Find the middle of the list
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Insert the new node after the middle node
    newNode->next = slow->next;
    slow->next = newNode;
}

// Function to delete the middle node from the list
void deleteMiddle(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return; // List is empty
    }

    struct Node* slow = *head_ref;
    struct Node* fast = *head_ref;
    struct Node* prev = NULL;

    // Find the middle of the list
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Delete the middle node
    if (prev != NULL) {
        prev->next = slow->next;
        free(slow);
    } else {
        // If there's only one element, update head
        *head_ref = slow->next;
        free(slow);
    }
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Create a linked list 1->2->3->4->5
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List: ");
    printList(head);

    // Insert a new node with data 10 in the middle
    insertMiddle(&head, 10);
    printf("After Inserting 10 in the Middle: ");
    printList(head);

    // Delete the middle node
    deleteMiddle(&head);
    printf("After Deleting Middle Node: ");
    printList(head);

    // Free the linked list
    freeList(head);
    return 0;
}
