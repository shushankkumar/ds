#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *link;
} *start;
// Insert a new node at the end
void Insert(int data)
{
struct node *first, *newnode;
newnode = (struct node *) malloc(sizeof(struct node));
newnode -> data = data;
if(start == NULL)
{
start = newnode;
start -> link = start;
}
else
{
first = start;
while(first -> link != start)
first = first -> link;
first -> link = newnode;
newnode -> link = start;
}
}
// Delete a node with a given key
void Delete(int item)
{
struct node *old, *temp;
temp = start;
do
{
if(temp -> data == item)
{
while(temp -> link != start)
temp = temp -> link;
temp -> link = start -> link;
start = start -> link;
return;
}
else
{
while(temp->link != start && temp->data != item)
{
old = temp;
temp = temp -> link;
}
if(temp -> link == start && temp -> data == item)
{
old -> link = start;
return;
}
else if (temp -> data == item)
{
old -> link = temp -> link;
return;
}
else
{
printf("\n\nElement %d not Found", item);
return;
}
}
}while(temp != start);
}
void Display()
{
struct node *temp = start;
printf("\n\tADDRESS\t INFO\tLINK\n");
do
{
printf("\t%u",temp);
printf("\t%d",temp -> data);
printf("\t%u\n",temp -> link);
temp = temp -> link;
}while(temp != start);
}
int main()
{
int choice, data, key, found;
do
{
printf("\nCircular Linked List Operations:\n");
printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
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