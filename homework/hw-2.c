#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
typedef struct {long long total, bread;} Dp;
Dp dp[10001];
Node *__rec_bst_insert(Node* root, int data, int level){
    if(root==NULL){
        dp[level].total += data;
        dp[level].bread++;
        return createNode(data);
    }

    if(data < root->data) 
        root -> left = __rec_bst_insert(root->left, data, level+1);
    else if(data > root->data) 
        root -> right = __rec_bst_insert(root->right, data, level+1);

    return root;
}

void bst_insert(Bst* bst, int data){
    bst->root = __rec_bst_insert(bst->root, data, 0);
    bst->__size++;
}

int main(){
    Bst bst;
    int n,k,x;
    scanf("%d",&n);
    while(n--){
        bst_init(&bst);
        memset(dp,0,sizeof(dp));
        while (scanf("%d",&x)==1 && x!= -1)
        {
            bst_insert(&bst, x);
        }
        for(int i=0; dp[i].total!=0; i++)
            printf("Level %d = %.2f\n",i,1.0*dp[i].total/dp[i].bread);
    }
}