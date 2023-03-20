#include <bits/stdc++.h>
using namespace std;

template<typename _T>
struct tree{
    private:
        typedef struct _node{
            _T value;
            struct _node *left, *right;
        } _node;
        _node *root = NULL;
        unsigned _size = 0;
        
        _node *_create_node(_T val){
            _node *newNode = (_node*)malloc(sizeof(_node));
            newNode -> value = val;
            newNode -> left = newNode -> right = NULL;
            return newNode;
        }
        _node *_rec_insert(_T val, _node *node){
            if(node == NULL){
                return _create_node(val);
            } else {
                if(val < node->value)
                    node->left = _rec_insert(val, node->left);
                else if(val > node->value)
                    node->right = _rec_insert(val, node->right);
            }
            return node;
        }
        _node *_find(_node *node, int x){
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

        void _inorder_rec(_node *node){
            if(node){
                _inorder_rec(node->left);
                cout << node->value << " ";
                _inorder_rec(node->right);
            }
        }

        void _preorder_rec(_node *node){
            if(node){
                cout << node->value << " ";
                _preorder_rec(node->left);
                _preorder_rec(node->right);
            }
        }

        void _postorder_rec(_node *node){
            if(node){
                _postorder_rec(node->left);
                _postorder_rec(node->right);
                cout << node->value << " ";
            }
        }

    public:
        void insert(_T val){
            root =  _rec_insert(val,root);
            _size++;
        }

        _node *find(_T num){
            return *_find(root, num);
        }

        void inorder(){
            _inorder_rec(root);
        }

        void preorder(){
            _preorder_rec(root);
        }

        void postorder(){
            _postorder_rec(root);
        }
};

int main(){
    tree<string> mytree;
    mytree.insert("abdul");
    mytree.insert("bagas");
    mytree.insert("karin");
    mytree.insert("aan");
    mytree.inorder();
    cout << "\n";
    mytree.preorder();
    cout << "\n";
    mytree.postorder();
    cout << "\n";

    return 0;
}