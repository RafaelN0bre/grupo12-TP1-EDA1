#ifndef AVL_H  
#define AVL_H

struct Node;

int height(struct Node *N);

int max(int a, int b);

struct Node *newNode(int key);

struct Node *rightRotate(struct Node *y);

struct Node *leftRotate(struct Node *x);

int getBalance(struct Node *N);

struct Node *insertNode(struct Node *node, int key);

struct Node *minValueNode(struct Node *node);

void printPreOrder(struct Node *root);

#endif