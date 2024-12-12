#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
} *start = NULL; // Initialize start to NULL

// Insert a new node at the end
void insert(int data) {
    struct Node *first, *newnode;
    newnode = (struct Node *) malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    newnode->link = NULL;

    if (start == NULL) {
        start = newnode;
    } else {
        first = start;
        while (first->link != NULL) {
            first = first->link;
        }
        first->link = newnode;
    }
}

// Delete a node with a given key
void delete(int key) {
    struct Node *old = NULL, *temp = start;

    while (temp != NULL) {
        if (temp->data == key) {
            if (temp == start) {
                start = temp->link;
            } else {
                old->link = temp->link;
            }
            free(temp);
            return;
        } else {
            old = temp;
            temp = temp->link;
        }
    }
    printf("\n\nElement %d not Found", key);
}

// Search for a node with a given key
int search(int key) {
    struct Node *temp = start;
    while (temp != NULL) {
        if (temp->data == key) {
            return 1; // Element found
        }
        temp = temp->link;
    }
    return 0; // Element not found
}

// Reverse the list
void reverse() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = NULL;
    struct Node *current = start;
    struct Node *link = NULL;

    while (current != NULL) {
        link = current->link;
        current->link = temp;
        temp = current;
        current = link;
    }
    start = temp;
}

// Display the list
void display() {
    struct Node *temp = start;
    printf("\n\tINFO\tLINK\n");
    while (temp != NULL) {
        printf("\t%d\t%p\n", temp->data, (void*)temp->link);
        temp = temp->link;
    }
}

int main() {
    int choice, data, key, found;
    do {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Reverse\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &key);
                found = search(key);
                if (found)
                    printf("Element %d found in the list.\n", key);
                else
                    printf("Element %d not found in the list.\n", key);
                break;
            case 4:
                reverse();
                printf("List reversed.\n");
                break;
            case 5:
                printf("List contents: ");
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
   } while (choice != 6);
   return 0;
}
   