#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data;
    struct __node *left, *right;
} Node;

typedef struct {
    Node *root;
    unsigned __size;
} Bst;

void bst_init(Bst*);
void bst_insert(Bst*, int);
Node *createNode(int);
Node *find(Bst*, int);
void print_inorder(Bst*);
void print_preorder(Bst*);
void print_postorder(Bst*);

Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

void bst_init(Bst* bst){
    bst->root = NULL;
    bst->__size = 0;
}

Node *__rec_bst_insert(Node* root, int data){
    if(root==NULL) 
        return createNode(data);

    if(data < root->data) 
        root -> left = __rec_bst_insert(root->left, data);
    else if(data > root->data) 
        root -> right = __rec_bst_insert(root->right, data);

    return root;
}

void bst_insert(Bst* bst, int data){
    bst->root = __rec_bst_insert(bst->root, data);
    bst->__size++;
}

Node *_find(Node *node, int x){
    while (node != NULL) {
        if (x < node->data)
            node = node->left;
        else if (x > node->data)
            node = node->right;
        else
            return node;
    }
    return NULL;
}

Node *find(Bst *bst, int x){
    Bst *temp = _find(bst->root, x);
    if (temp)
        return temp;
    else
        return NULL;
}

void __inorder(Node *root) {
    if (root) {
        __inorder(root->left);
        printf("%d ", root->data);
        __inorder(root->right);
    }
}

void __postorder(Node *root) {
    if (root) {
        __postorder(root->left);
        __postorder(root->right);
        printf("%d ", root->data);
    }
}

void __preorder(Node *root) {
    if (root) {
        printf("%d ", root->data);
        __preorder(root->left);
        __preorder(root->right);
    }
}

void print_inorder(Bst* bst){
    __inorder(bst->root);
}
void print_preorder(Bst* bst){
    __preorder(bst->root);
}
void print_postorder(Bst* bst){
    __postorder(bst->root);
}