#include <stdio.h>
#include <stdlib.h> // For exit function
#define MAX 10

int SQ[MAX];
int front = -1, rear = -1;

void Insert(int item) // Adds an Element to the Queue
{
    if (rear == MAX - 1)
    {
        printf("\nQueue Is Full\n");
        return;
    }
    SQ[++rear] = item;
    if (front == -1)
        front = 0;
}

int Delete() // Removes an element from the Queue
{
    int data;
    if (front == -1)
    {
        printf("\nQueue is Empty\n");
        return 0;
    }
    data = SQ[front];
    SQ[front] = 0; // Optional: Clear the position
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return data;
}

void Display() // View the Data of Queue
{
    printf("\n\t\t\tInformation in Queue\n\n");
    if (front == -1)
    {
        printf("\t\t| ");
        for (int i = 0; i < MAX; i++)
            printf(" | ");
        printf("\n\n");
    }
    else
    {
        printf("\t\t | ");
        for (int i = front; i <= rear; i++)
            printf("%d | ", SQ[i]);
        printf("\n\n");
    }
}

int main() // Changed void to int
{
    int item;
    int ch;

    do
    {
        printf("\n\t\tPress 1 for Insert Item Into Queue");
        printf("\n\t\tPress 2 for Delete Item From Queue");
        printf("\n\t\tPress 3 for Display Data of Queue");
        printf("\n\t\tPress 4 for Exit");
        printf("\n\n\t\tEnter Your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter Item to Insert : ");
            scanf("%d", &item);
            Insert(item);
            break;
        case 2:
            item = Delete();
            printf("\nItem %d is Deleted\n", item);
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice! Please try again.\n");
        }
    } while (ch != 4);

    return 0; // Added return statement
}