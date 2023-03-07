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

long long dp[100001];
Node *__rec_bst_insert(Node* root, int data, int level){
    if(root==NULL){
        dp[level] += data;
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



// long long solve(Node *node, int level, int currLevel){
//     if(node == NULL || currLevel>level) return 0;
//     if(level==currLevel) return node->data;
//     currLevel++;
//     return solve(node->left, level, currLevel) + solve(node->right, level, currLevel);
// }


int main(){
    memset(dp,0,sizeof(dp));
    Bst bst;
    bst_init(&bst);
    int n,k,x;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&k);
        if(k==1){
            scanf("%d",&x);
            bst_insert(&bst, x);
        } else {
            scanf("%d", &x);
            // solve(bst.root, x, 0);
            if(dp[x])
                printf("Level %d: %lld\n",x, dp[x]);
            else
                printf("GG EZ\n");
        }
    }
}