#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    long long data;
    struct __node *left, *right, *parent;
} Node;

typedef struct {
    Node *root;
    unsigned __size;
} Bst;

void bst_init(Bst*);
void bst_insert(Bst*, long long);
Node *createNode(long long);

Node *createNode(long long data){
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

Node *__rec_bst_insert(Node* root, long long data){
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

void bst_insert(Bst* bst, long long data){
    bst->root = __rec_bst_insert(bst->root, data);
    bst->__size++;
}

long long isFound,yz;

void cari(Node* node){
    // if(isFound) return;
    if(isFound){
        return;
    } else {
        if(node && node->left && node->right &&
            (node->data + node->right->data + node->left->data == yz) ){
            isFound=1; 
            return;
        }
        if(node && node->parent){
            long long temp = node->parent->data + node->data;
            if(yz-temp > node->data && node->right){
                if(temp + node->right->data == yz){
                    isFound=1;
                    return;
                } else
                    cari(node->right);
            } else if(node -> left){
                if(temp + node->left->data == yz){
                    isFound=1;
                    return;
                } else
                    cari(node->left);
            }
        } else {
            if(node && node->left)
                cari(node->left);
            if(node && node->right)
                cari(node->right);
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
    printf("%lld ", yz);
    if(isFound) puts("Selamat! Kalian menemukan harta karunnya");
    else puts("Tidak ada kombinasi yang tepat! Bikin ulang.");
    return 0;
}