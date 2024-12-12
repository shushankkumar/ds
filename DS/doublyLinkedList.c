#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node *prev;
struct Node *next;
}*start;
// Insert a new node at the end
void insert(int data)
{
struct Node *first, *newnode;
newnode = (struct Node *) malloc(sizeof(struct Node));
newnode -> data = data;
newnode -> next = NULL;
newnode -> prev = NULL;
if(start == NULL)
start = newnode;
else
{
first = start;
while(first -> next != NULL)
first = first -> next;
newnode -> prev = first;
first -> next = newnode;
}
}
// Delete a node with a given key
void delete(int key)
{
struct Node *temp;
if (start == NULL)
{
printf("List is empty.\n");
return;
}
temp = start;
while (temp != NULL && temp->data != key)
temp = temp->next;
if (temp->data != key)
{
printf("Element %d not found.\n", key);
return;
}
if (temp->prev)
temp->prev->next = temp->next;
else
start = temp->next;
if (temp->next)
temp->next->prev = temp->prev;
printf("Element %d deleted.\n", key);
}
// Search for a node with a given key
int search(int key)
{
struct Node *temp;
temp = start;
while (temp->next != NULL)
{
if (temp->data == key)
return 1;
temp = temp ->next;
}
return 0;
}
// Reverse the list
void reverse()
{
if (start == NULL)
{
printf("List is empty.\n");
return;
}
struct Node *temp = NULL;
struct Node *current;
current = start;
while (current)
{
temp = current->prev;
current->prev = current->next;
current->next = temp;
current = current->prev;
}
if (temp)
start = temp->prev;
}
// Display the list
void display()
{
struct Node *temp = start;
printf("\n\t\t\tPREV\t\t\t ADD\t\t INFO\t\t\tNEXT\n");
while(temp != NULL)
{
printf("\t\t%10u",temp -> prev);
printf("\t\t%10u",temp);
printf("\t%10d",temp -> data);
printf("\t\t%10u\n",temp -> next);
temp = temp -> next;
}
}
int main()
{
int choice, data, key, found;
do
{
printf("\nDoubly Linked List Operations:\n");
printf("1. Insert\n2. Delete\n3. Search\n4. Reverse\n5. Display\n6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
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