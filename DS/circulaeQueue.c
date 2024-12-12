#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *start = NULL; // Initialize start to NULL

// Insert a new node at the end
void Insert(int data) {
    struct node *first, *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;

    if (start == NULL) {
        start = newnode;
        start->link = start; // Point to itself, making it circular
    } else {
        first = start;
        while (first->link != start) {
            first = first->link; // Traverse to the last node
        }
        first->link = newnode; // Link the last node to the new node
        newnode->link = start; // New node points to start
    }
}

// Delete a node with a given key
void Delete(int item) {
    struct node *old, *temp;
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    temp = start;
    do {
        if (temp->data == item) {
            // If the node to delete is the start node
            if (temp == start) {
                // Find the last node
                while (temp->link != start) {
                    temp = temp->link;
                }
                // If there's only one node
                if (start->link == start) {
                    free(start);
                    start = NULL; // List becomes empty
                } else {
                    temp->link = start->link; // Last node points to the second node
                    free(start);
                    start = temp->link; // Update start to the new first node
                }
            } else {
                // Node to delete is not the start node
                old->link = temp->link; // Bypass the node to delete
                free(temp);
            }
            return;
        }
        old = temp;
        temp = temp->link;
    } while (temp != start);

    printf("\n\nElement %d not Found", item);
}

// Display the list
void Display() {
    struct node *temp = start;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("\n\tADDRESS\t INFO\tLINK\n");
    do {
        printf("\t%p", (void*)temp); // Use %p for pointer addresses
        printf("\t%d", temp->data);
        printf("\t%p\n", (void*)temp->link);
        temp = temp->link;
    } while (temp != start);
}

int main() {
    int choice, data, key;
    do {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                Insert(data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                Delete(key);
                break;
            case 3:
                printf("List contents: ");
                Display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
    return 0;
}