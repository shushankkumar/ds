#include <stdio.h>
#include <stdlib.h>
#define MAX_KEYS 3 //Max number of keys in a node (order of the tree)
#define MIN_KEYS (MAX_KEYS / 2) // Minimum number of keys
struct Node
{
int keys[MAX_KEYS + 1]; // Array to hold keys (1 extra for split)
struct Node* children[MAX_KEYS + 2]; // Array of child pointers
int isLeaf; // 1 if leaf, 0 otherwise
int numKeys; // Current number of keys
struct Node* next; // Pointer to the next leaf (for leaf nodes)
} Node;
// Function prototypes
struct Node* createNode(int isLeaf);
void insert(struct Node** root, int key);
void splitChild(struct Node* parent, int index, struct Node* child);
void insertNonFull(struct Node* node, int key);
void printTree(struct Node* root);
// Create a new node
struct Node* createNode(int isLeaf)
{
struct Node* node = (struct Node*)malloc(sizeof(Node));
node->isLeaf = isLeaf;
node->numKeys = 0;
for (int i = 0; i < MAX_KEYS + 2; i++)
node->children[i] = NULL;
node->next = NULL;
return node;
}
// Insert a key into the B+ tree
void insert(struct Node** root, int key)
{
struct Node* r = *root;
if (r == NULL)
{
// Create a new root if the tree is empty
*root = createNode(1);
(*root)->keys[0] = key;
(*root)->numKeys = 1;
}
else
{
if (r->numKeys == MAX_KEYS)
{
// Root is full; split
struct Node* s = createNode(0); // New root
s->children[0] = r;
splitChild(s, 0, r);
*root = s;
insertNonFull(s, key);
}
else
insertNonFull(r, key);
}
}
// Split a child node
void splitChild(struct Node* parent, int index, struct Node* child)
{
struct Node* newChild = createNode(child->isLeaf);
newChild->numKeys = MIN_KEYS;
// Move the second half of keys to the new child
for (int i = 0; i < MIN_KEYS; i++)
newChild->keys[i] = child->keys[i + MIN_KEYS + 1];
if (!child->isLeaf)
{
for (int i = 0; i <= MIN_KEYS; i++)
newChild->children[i] = child->children[i+MIN_KEYS+1];
}
child->numKeys = MIN_KEYS;
// Insert the new child into the parent
for (int i = parent->numKeys; i > index; i--)
{
parent->children[i + 1] = parent->children[i];
parent->keys[i] = parent->keys[i - 1];
}
parent->children[index + 1] = newChild;
parent->keys[index] = child->keys[MIN_KEYS];
parent->numKeys++;
}
// Insert a key into a non-full node
void insertNonFull(struct Node* node, int key)
{
int i = node->numKeys - 1;
if (node->isLeaf)
{
// Insert into the leaf
while (i >= 0 && key < node->keys[i])
{
node->keys[i + 1] = node->keys[i];
i--;
}
node->keys[i + 1] = key;
node->numKeys++;
}
else
{
// Find the child to insert into
while (i >= 0 && key < node->keys[i])
i--;
i++;
if (node->children[i]->numKeys == MAX_KEYS)
{
splitChild(node, i, node->children[i]);
if (key > node->keys[i])
i++;
}
insertNonFull(node->children[i], key);
}
}
// Print the B+ tree
void printTree(struct Node* root)
{
if (root != NULL)
{
for (int i = 0; i < root->numKeys; i++)
printf("%d ", root->keys[i]);
printf("\n");
if (!root->isLeaf)
{
for (int i = 0; i <= root->numKeys; i++)
printTree(root->children[i]);
}
}
}
// Main function
int main()
{
struct Node* root = NULL;
int keys[] = {10, 20, 5, 6, 12, 30, 7, 17};
int n = sizeof(keys) / sizeof(keys[0]);
for (int i = 0; i < n; i++)
insert(&root, keys[i]);
printf("B+ Tree:\n");
printTree(root);
return 0;
}