// STACK
#include<stdio.h>
#define max 5
int stack[max];
int top = -1;
void push()
{
int x;
if(top>=max-1)
printf(“\n\astack overflow”);
else
{
top++;
printf("\n enter stack element:");
scanf("%d",&x);
stack[top]=x;
}
}
int pop()
{
int x;
if(top==-1)
{
printf("\n\a stack underflow");
return 0;
}
else
{
x=stack[top];
top--;
return(x);
}
}
int peep()
{
int i;
printf("\n enter position of element: ");
scanf("%d",&i);
if (top-i+1<0)
{
printf("\n\a stack overflow");
return 0;
}
else
return(stack[top-i+1]);
}
void change()
{
int i, x;
printf("\nEnter position of element you want to change");
scanf("%d",&i);
printf("\nEnter the new element:");
scanf("%d",&x);
if(top-i+1<0)
printf("\nStack Underflow");
else
stack[top-i+1]=x;
}
void display()
{
int i;
if(top==-1)
printf("\nStack is Empty");
else
{
printf("\nStack elements are:");
for(i=top;i>=0;i--)
printf("\n| stack[i] |");
}
}
void main()
{
int x,ch;
do
{
printf("\nEnter 1 for PUSH");
printf("\nEnter 2 for POP");
printf("\nEnter 3 for PEEP");
printf("\nEnter 4 for CHANGE");
printf("\nEnter 5 for DISPLAY");
printf("\nEnter 6 for EXIT");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
push();
break;
case 2:
x=pop();
if(x != 0)
printf("\nPoped Element: %d", x);
break;
case 3:
x=peep();
printf("\n the ith element is: %d", x);
break;
case 4:
change();
break;
case 5:
display();
break;
}
}while(ch!=6);
}