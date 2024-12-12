// Using Linked List
#include<stdio.h>
#include<stdlib.h>
#define MAX 100 // Maximum degree of the polynomial
struct Node
{
int coeff; // Coefficient
int expo; // Exponent
struct Node* next; // Pointer to the next term
} *poly1, *poly2, *New, *result;
void createPoly(struct Node *poly, int exp, int p)
{
struct Node *first;
int i;
for(i = exp ; i >= 0 ; i--)
{
struct Node *New = (struct Node*)malloc(sizeof(struct Node));
printf("Enter coefficient for x^%d: ", i);
scanf("%d", &New->coeff);
New->expo = i;
New->next = NULL;
if(poly == NULL)
poly = New;
else
{
first = poly;
while(first->next != NULL)
first = first->next;
first->next = New;
}
}
if(p == 1)
poly1 = poly;
else
poly2 = poly;
}
void createResult(struct Node *poly, int exp)
{
struct Node *first;
int i;
for(i = exp ; i >= 0 ; i--)
{
struct Node *New = (struct Node*)malloc(sizeof(struct Node));
New->coeff = 0;
New->expo = i;
New->next = NULL;
if(poly == NULL)
poly = New;
else
{
first = poly;
while(first->next != NULL)
first = first->next;
first->next = New;
}
}
result = poly;
}
void addPolynomials(struct Node *p1, struct Node *p2, struct Node *res)
{
while(p1)
{
res->coeff = p1->coeff + p2->coeff;
res = res->next;
p1 = p1->next;
p2 = p2->next;
}
}
void printPolynomial(struct Node *poly)
{
while (poly)
{
printf("%d", poly->coeff);
if (poly->expo != 0)
printf("x^%d", poly->expo);
poly = poly->next;
if (poly && poly->coeff > 0)
printf(" + ");
}
printf("\n");
}
void main()
{
int degree1, degree2, maxDegree, i, coeff;
// Input first polynomial
printf("Enter degree of the first polynomial: ");
scanf("%d", &degree1);
printf("Enter coefficients for the first polynomial:\n");
createPoly(poly1, degree1, 1);
printf("Enter degree of the second polynomial: ");
scanf("%d", &degree2);
printf("Enter coefficients for the second polynomial:\n");
createPoly(poly2, degree2, 2);
// Determine maximum degree
if(degree1 > degree2)
maxDegree = degree1;
else
maxDegree = degree2;
createResult(result, maxDegree);
// Add the polynomials
addPolynomials(poly1, poly2, result);
printf("First polynomial is: ");
printPolynomial(poly1);
printf("Second polynomial is: ");
printPolynomial(poly2);
printf("Sum of the polynomials is: ");
printPolynomial(result);
//getch();
}