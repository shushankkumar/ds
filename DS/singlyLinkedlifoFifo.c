#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *start;
void Ins_LIFO(int item)
{
    struct node *first, *newnode;
    if (start == NULL)
    {
        first = (struct node *)malloc(sizeof(struct node));
        first->data = item;
        first->link = NULL;
        start = first;
    }
    else
    {
        first = start;
        while (first->link != NULL)
            first = first->link;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = item;
        newnode->link = NULL;
        first->link = newnode;
    }
}
void Ins_FIFO(int item)
{
    struct node *first, *newnode;
    if (start == NULL)
    {
        first = (struct node *)malloc(sizeof(struct node));
        first->data = item;
        first->link = NULL;
        start = first;
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = item;
        newnode->link = start;
        start = newnode;
    }
}
void Del_LIFO()
{
    struct node *first, *prev;
    if (start == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (start->link == NULL)
    {
        printf("\nNode %d is deleted", start->data);
        start = NULL;
        free(start);
    }
    else
    {
        first = start;
        while (first->link != NULL)
        {
            prev = first;
            first = first->link;
        }
        printf("\nNode %d is deleted", first->data);
        prev->link = NULL;
        free(first);
    }
}
void Del_FIFO()
{
    struct node *first;
    if (start == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (start->link == NULL)
    {
        printf("\nNode %d is deleted", start->data);
        start = NULL;
        free(start);
    }
    else
    {
        printf("\nNode %d is deleted", start->data);
        start = start->link;
    }
}
void Display()
{
    struct node *temp = start;
    printf("\n\t\t\t ADD\t\t INFO\t\t\tLINK\n");
    while (temp != NULL)
    {
        printf("\t\t%10u", temp);
        printf("\t%10d", temp->data);
        printf("\t\t%10u\n", temp->link);
        temp = temp->link;
    }
}
int LIFO()
{
    int ch, item;
    do
    {
        printf("\nPress 1 for Insertion");
        printf("\nPress 2 for Deletion");
        printf("\nPress 3 for Display");
        printf("\nPress 4 for Exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Item: ");
            scanf("%d", &item);
            Ins_LIFO(item);
            break;
        case 2:
            Del_LIFO();
            break;
        case 3:
            Display();
            break;
        case 4:
            break;
        default:
            printf("\nInvalid Input");
        }
    } while (ch != 4);
    return 0;
}
int FIFO()
{
    int ch, item;
    do
    {
        printf("\nPress 1 for Insertion");
        printf("\nPress 2 for Deletion");
        printf("\nPress 3 for Display");
        printf("\nPress 4 for Exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Item: ");
            scanf("%d", &item);
            Ins_LIFO(item);
            break;
        case 2:
            Del_LIFO();
            break;
        case 3:
            Display();
            break;
        case 4:
            break;
        default:
            printf("\nInvalid Input");
        }
    } while (ch != 4);
    return 0;
}
int main()
{
    int ch;
    do
    {
        printf("\nPress 1 for LIFO Procedure");
        printf("\nPress 2 for FIFO Procedure");
        printf("\nPress 3 for Exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            LIFO();
            break;
        case 2:
            FIFO();
            break;
        case 3:
            break;
        default:
            printf("\nInvalid Input");
        }
    } while (ch != 3);
    return 0;
}