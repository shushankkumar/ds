#include <stdio.h>
#include <stdlib.h>
// Node structure for the binary search tree
struct Node
{
int data;
struct Node* left;
struct Node* right;
} Node;
// Function to create a new node
struct Node* createNode(int data)
{
struct Node* newNode = (struct Node*)malloc(sizeof(Node));
newNode->data = data;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}
// Function to insert a node into the binary search tree
struct Node* insertNode(struct Node* root, int data)
{
if (root == NULL)
return createNode(data);
if (data < root->data)
root->left = insertNode(root->left, data);
else if (data > root->data)
root->right = insertNode(root->right, data);
return root;
}
// Function for inorder traversal (Left, Root, Right)
void inorderTraversal(struct Node* root)
{
if (root != NULL)
{
inorderTraversal(root->left);
printf("%d ", root->data);
inorderTraversal(root->right);
}
}
// Function for preorder traversal (Root, Left, Right)
void preorderTraversal(struct Node* root)
{
if (root != NULL)
{
printf("%d ", root->data);
preorderTraversal(root->left);
preorderTraversal(root->right);
}
}
// Function for postorder traversal (Left, Right, Root)
void postorderTraversal(struct Node* root)
{
if (root != NULL)
{
postorderTraversal(root->left);
postorderTraversal(root->right);
printf("%d ", root->data);
}
}
int main()
{
struct Node* root = NULL;
int choice, data;
while (1)
{
printf("Binary Search Tree Operations\n");
printf("1. Insert Node\n");
printf("2. Inorder Traversal\n");
printf("3. Preorder Traversal\n");
printf("4. Postorder Traversal\n");
printf("5. Exit\n");
printf("\nEnter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter the value to insert: ");
scanf("%d", &data);
root = insertNode(root, data);
break;
case 2:
printf("Inorder Traversal: ");
inorderTraversal(root);
printf("\n");
break;
case 3:
printf("Preorder Traversal: ");
preorderTraversal(root);
printf("\n");
break;
case 4:
printf("Postorder Traversal: ");
postorderTraversal(root);
printf("\n");
break;
case 5:
printf("Exiting program.\n");
exit(0);
default:
printf("Invalid choice! Please try again.\n");
}
}
return 0;
}