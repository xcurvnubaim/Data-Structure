#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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
// Node *find(Bst*, int);
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

// Node *__rec__find(Node* node, int data){
//     if(data==node->data) return node;
//     else if(data<node->data) return __rec__find(node->left, data);
//     else return __rec__find(node->right, data);
// }

// Node *find(Bst* bst, int data){
//     return __rec__find(bst->root, data);
// }


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

void order(Bst *bst, int *arr, int begin, int end){
    if(begin==end) bst_insert(bst,arr[begin]);
    else if(begin+1==end){
        bst_insert(bst,arr[end]);
        bst_insert(bst,arr[begin]);
    }
    else {
        int mid = ceil((begin+end)/2.0);
        bst_insert(bst,arr[mid]);
        order(bst,arr,begin,mid-1);
        order(bst,arr,mid+1,end);
    }
}

int main(){
    Bst bst;
    bst_init(&bst);
    int x;
    scanf("%d",&x);
    int arr[x];
    for(int i=0;i<x;i++) scanf("%d",&arr[i]);
    order(&bst,arr,0,x-1);
    print_preorder(&bst);
    puts(""); 
    // print_inorder(&bst);
    for(int i=0;i<x;i++) printf("%d ",arr[i]);
    puts("");
    print_postorder(&bst);
    puts("");
    return 0;
}