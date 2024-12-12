#include <stdio.h>
#define MAX 10
int front = -1, rear = -1;
struct PQ
{
int val;
int PR;
}Q[MAX];
void Insert()
{
int i, j,tmpV, tmpP;
if(rear >= MAX-1)
{
printf("Priority Queue id FULL");
return;
}
rear++;
printf("Enter Value: ");
scanf("%d",&Q[rear].val);
printf("Enter Priority: ");
scanf("%d",&Q[rear].PR);
if(front == -1)
front = 0;
for(i=0;i<=rear;i++)
{
for(j=0;j<=rear;j++)
{
if(Q[i].PR > Q[j].PR)
{
tmpV = Q[i].val;
tmpP = Q[i].PR;
Q[i].val = Q[j].val;
Q[i].PR = Q[j].PR;
Q[j].val = tmpV;
Q[j].PR = tmpP;
}
}
}
}
void Delete()
{
int i, j,tmpV, tmpP;
if(front == -1)
{
printf("Priority Queue id EMPTY");
return;
}
printf("%d is deleted", Q[front]);
Q[front].val = 0;
Q[front].PR = 0;
if(front == rear)
front = rear = -1;
else
front++;
}
void Display()
{
int i;
if(front == -1)
{
printf("Priority Queue id EMPTY");
return;
}
else
{
printf("|");
for(i=0;i<MAX;i++)
{
printf(" %2d |",Q[i].PR);
}
printf("\n|");
for(i=0;i<MAX;i++)
{
printf(" %2d |",Q[i].val);
}
}
}
int main()
{
int ch;
do
{
printf("\nPress 1 for Insert");
printf("\nPress 2 for Delete");
printf("\nPress 3 for Display");
printf("\nPress 4 for Exit");
printf("\nEnter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
Insert();
break;
case 2:
Delete();
break;
case 3:
Display();
break;
case 4:
break;
default:
printf("Wrong Choice!");
}
}while(ch != 4);
return 0;
}