#include <stdio.h>
#include <stdlib.h>
#define MAX 3 // Maximum number of keys in a node
#define MIN (MAX / 2) // Minimum degree of the tree
struct BTNode
{
int keys[MAX];
struct BTNode* children[MAX + 1];
int n; // Number of keys in the node
int leaf; // 1 if leaf, 0 otherwise
} BTNode;
struct BTNode* createNode(int leaf)
{
struct BTNode* New = (struct BTNode*)malloc(sizeof(BTNode));
New->leaf = leaf;
New->n = 0;
for (int i = 0; i <= MAX; i++)
New->children[i] = NULL;
return New;
}
// Split a full child node
void splitChild(struct BTNode* parent, int i, struct BTNode* fullChild)
{
struct BTNode* newChild = createNode(fullChild->leaf);
newChild->n = MIN;
// Move the second half of keys to the new child
for (int j = 0; j < MIN; j++)
newChild->keys[j] = fullChild->keys[j + MIN + 1];
// Move children if not a leaf
if (!fullChild->leaf)
{
for (int j = 0; j <= MIN; j++)
newChild->children[j] = fullChild->children[j + MIN + 1];
}
fullChild->n = MIN;
// Make space for the new child in the parent
for (int j = parent->n; j >= i + 1; j--)
parent->children[j + 1] = parent->children[j];
parent->children[i + 1] = newChild;
// Move the middle key of fullChild to the parent
for (int j = parent->n - 1; j >= i; j--)
parent->keys[j + 1] = parent->keys[j];
parent->keys[i] = fullChild->keys[MIN];
parent->n++;
}
// Insert non-full node
void insertNonFull(struct BTNode* node, int key)
{
int i = node->n - 1;
if (node->leaf)
{
// Insert the key into the correct position
while (i >= 0 && key < node->keys[i])
{
node->keys[i + 1] = node->keys[i];
i--;
}
node->keys[i + 1] = key;
node->n++;
}
else
{
// Find the child to insert the key into
while (i >= 0 && key < node->keys[i])
i--;
i++;
// If the child is full, split it
if (node->children[i]->n == MAX)
{
splitChild(node, i, node->children[i]);
if (key > node->keys[i])
i++;
}
insertNonFull(node->children[i], key);
}
}
// Insert key into the B-tree
struct BTNode* insert(struct BTNode* root, int key)
{
if (root->n == MAX)
{
// Root is full; split it
struct BTNode* newRoot = createNode(0);
newRoot->children[0] = root;
splitChild(newRoot, 0, root);
// Decide which child to insert into
int i = (key > newRoot->keys[0]) ? 1 : 0;
insertNonFull(newRoot->children[i], key);
return newRoot;
} else {
insertNonFull(root, key);
return root;
}
}
// Utility function to print the B-tree
void printTree(struct BTNode* root, int level) {
if (root) {
printf("Level %d: ", level);
for (int i = 0; i < root->n; i++) {
printf("%d ", root->keys[i]);
}
printf("\n");
for (int i = 0; i <= root->n; i++) {
printTree(root->children[i], level + 1);
}
}
}
int main() {
struct BTNode* root = createNode(1); // Start with an empty tree
// Insert keys into the B-tree
int keys[] = {10, 20, 5, 6, 12, 30, 7, 17};
int n = sizeof(keys) / sizeof(keys[0]);
for (int i = 0; i < n; i++) {
root = insert(root, keys[i]);
}
// Print the B-tree
printf("B-tree structure:\n");
printTree(root, 0);
return 0;
}