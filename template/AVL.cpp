#include <bits/stdc++.h>
using namespace std;

    
template<typename T>
struct AVL{
private:
    typedef struct _node {
        int value;
        int height;
        struct _node *left, *right;
    } _node;
    _node *root;
    unsigned size;

    _node *createNode(T val){
        _node *newNode = (_node*)malloc(sizeof(_node));
        newNode->value = val;
        newNode->height =1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    _node *_search(_node *root, T value) {
        while (root != NULL) {
            if (value < root->value)
                root = root->left;
            else if (value > root->value)
                root = root->right;
            else
                return root;
        }
        return NULL;
    }

    int _getHeight(_node* node){
        return node ? node->height : 0; 
    }

    int getBF(_node *node){
        return _getHeight(node->left) - 
        _getHeight(node->right);
    }

    _node* _rightRotate(_node* pivotNode){
        _node* newParrent=pivotNode->left;
        pivotNode->left=newParrent->right;
        newParrent->right=pivotNode;

        pivotNode->height=max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    _node* _leftRotate(_node* pivotNode) {
        _node* newParrent=pivotNode->right;
        pivotNode->right=newParrent->left;
        newParrent->left=pivotNode;

        pivotNode->height= max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height= max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    int _getBalanceFactor(_node* node){
        if(node==NULL)
            return 0;
        return _getHeight(node->left)-_getHeight(node->right);
    }

    _node* _insert_AVL(_node* node,int value) {
        
        if(node==NULL)
            return createNode(value);
        else if(value < node->value)
            node->left = _insert_AVL(node->left,value);
        else if(value > node->value)
            node->right = _insert_AVL(node->right,value);
        
        node->height= 1 + max(_getHeight(node->left),_getHeight(node->right)); 

        int bf = getBF(node);
        
        // L
        if(bf > 1 && value < node->left->value)
            return _rightRotate(node);
        // LR
        if(bf > 1 && value > node->left->value){
            node->left = _leftRotate(node->left);
            return _rightRotate(node);
        }
        // R
        if(bf < -1 && value > node->right->value)
            return _leftRotate(node);
        // RL
        if(bf < -1 && value < node->right->value){
            node->right = _rightRotate(node->right);
            return _leftRotate(node);
        }
        return node;
    }

    _node* _findMinNode(_node *node) {
        _node *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    // _node* _remove_AVL(_node* node,int value){
    //     if(node==NULL)
    //         return node;
    //     if(value > node->value)
    //         node->right=_remove_AVL(node->right,value);
    //     else if(value < node->value)
    //         node->left=_remove_AVL(node->left,value);
    //     else{
    //         _node *temp;
    //         if((node->left==NULL)||(node->right==NULL)){
    //             temp=NULL;
    //             if(node->left==NULL) temp=node->right;  
    //             else if(node->right==NULL) temp=node->left;
                
    //             if(temp==NULL){
    //                 temp=node;
    //                 node=NULL;
    //             }
    //             else
    //                 *node=*temp;   
                
    //             free(temp);
    //         }
    //         else{
    //             temp = _findMinNode(node->right);
    //             node->value=temp->value;
    //             node->right=_remove_AVL(node->right,temp->value);
    //         }    
    //     }

    //     if(node==NULL) return node;
        
    //     node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

    //     int balanceFactor= _getBalanceFactor(node);
        
    //     if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
    //         return _leftCaseRotate(node);

    //     if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
    //         return _leftRightCaseRotate(node);
    
    //     if(balanceFactor<-1 && _getBalanceFactor(node->right)<=0) 
    //         return _rightCaseRotate(node);

    //     if(balanceFactor<-1 && _getBalanceFactor(node->right)>0) 
    //         return _rightLeftCaseRotate(node);
        
    //     return node;
    // }

    void _inorder(_node *node) {
        if (node) {
            _inorder(node->left);
            printf("%d ", node->value);
            _inorder(node->right);
        }
    }

public:
    void init() {
        root = NULL;
        size = 0U;
    }

    bool isEmpty() {
        return root == NULL;
    }

    bool find(int value) {
        _node *temp = _search(root, value);
        if (temp == NULL)
            return false;
        
        if (temp->value == value) return true;
        else return false;
    }

    void insert(int value) {
        if (!find(value)) {
            root = _insert_AVL(root, value);
            size++;
        }
    }

    // void remove(int value) {
    //     if (find(value)) {
    //         root = _remove_AVL(root, value);
    //         size--;
    //     }
    // }

    void inorder() {
        this->_inorder(root);
    }

};

int main(){
    AVL<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);
    return 0;
}