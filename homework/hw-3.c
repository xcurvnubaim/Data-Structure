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
Node *find(Bst*, int);

Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
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

Node *__rec__find(Node* node, int data){
    if(data==node->data) return node;
    else if(data<node->data) return __rec__find(node->left, data);
    else return __rec__find(node->right, data);
}

Node *find(Bst* bst, int data){
    return __rec__find(bst->root, data);
}

int main(){
    Bst bst;
    bst_init(&bst);
    int n,x;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&x);
        bst_insert(&bst, x);
    }
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&x);
        Node *res_find = find(&bst, x);
        if(res_find->parent) printf("%d", res_find->parent->data);
        else printf("-1");
        if(res_find->left) printf(" %d", res_find->left->data);
        if(res_find->right) printf(" %d", res_find->right->data);
        printf("\n");
    }
    
    return 0;
}