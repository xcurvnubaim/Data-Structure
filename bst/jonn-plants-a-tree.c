#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *left, *right;
}Node;

typedef struct tree{
    Node *root;
    unsigned _size;
} BST;

void bst_init(BST*);
void bst_insert(BST*, int );
void bst_transversal_inorder(Node*);
void bst_transversal_preorder(Node*);
void bst_transversal_postorder(Node*);
Node *createNode(int);

Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void bst_init(BST* bst){
    bst->root = NULL;
    bst->_size = 0;
}

Node *__insert(Node* root, int data){
    Node *temp = createNode(data);

}

void bst_insert(BST *bst, int data){

}


int main(){

    return 0;
}