#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data;
    struct __node *left, *right, *parent;
} Node;

typedef struct {
    Node *root;
    unsigned __size;
} Bst;

void bst_init(Bst*);
void bst_insert(Bst*, int);
Node *createNode(int);

Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> parent = NULL;
    return newNode;
}

void bst_init(Bst* bst){
    bst->root = NULL;
    bst->__size = 0;
}

Node *__rec_bst_insert(Node* root, int data){
    if(root==NULL) 
        return createNode(data);

    if(data < root->data){
        root -> left = __rec_bst_insert(root->left, data);
        root -> left -> parent = root;
    }
    else if(data > root->data){
        root -> right = __rec_bst_insert(root->right, data);
        root -> right -> parent = root;
    } 

    return root;
}

void bst_insert(Bst* bst, int data){
    bst->root = __rec_bst_insert(bst->root, data);
    bst->__size++;
}
int isFound;
long long yz;
void cari(Node *node){
    if(node && !isFound){
        if(node->parent){
            long long temp = node->data + node->parent->data;
            if(node->left){
                if(temp + node->left->data==yz){
                    isFound=1;
                    return;
                } else {
                    cari(node->left);
                }
            }
            if(node->right){
                if(temp + node->right->data==yz){
                    isFound=1;
                    return;
                } else {
                    cari(node->right);
                }
            }
        }
        if(node->left && node->right &&(
            node->data + node->left->data + node->right->data == yz
        ))
        {
            isFound=1;
            return;
        }
    }
}

int main(){
    Bst bst;
    bst_init(&bst);
    int n,x;
    isFound=0;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&x);
        bst_insert(&bst,x);
    }
    scanf("%lld",&yz);
    cari(bst.root);
    cari(bst.root->right);
    cari(bst.root->left);
    if(isFound) puts("ManTap");
    else puts("HAiiyyaAhh SalAhh");
    return 0;
}