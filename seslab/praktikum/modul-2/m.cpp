#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

template<typename _T>
struct tree{
    private:
        typedef struct _node{
            _T value;
            int height;
            struct _node *left, *right;
        } _node;
        
        _node *root = NULL;
        unsigned _size = 0;

        _node *_create_node(_T val){
            _node *newNode = (_node*)malloc(sizeof(_node));
            newNode -> value = val;
            newNode -> left = newNode -> right = NULL;
            newNode -> height = 0;
            return newNode;
        }

        int get_height(_node *node){
            if(node){
                return node->height;
            } else {
                return -1;
            }
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

            node->height = max(get_height(node->left),get_height(node->right)) + 1;

            return node;
        }

        // void _iterative_insert(_T val){
        //     if(root==NULL)
        //         root = _create_node(val);
        //     else{
        //         _node *node= root;
        //         while(node){
        //             if(val < node->value){
        //                 if(node->left)
        //                     node = node->left;
        //                 else{
        //                     node->left = _create_node(val); 
        //                     break;
        //                 }
        //             } else if(val > node->value)
        //                 if(node->right)
        //                     node = node->right;
        //                 else{
        //                     node->right = _create_node(val); 
        //                     break;
        //                 }
        //             else
        //                 return;
        //         }
        //     }
        //     _size++;
        // }

        _node *_find(_node *node, _T x){
            while (node != NULL) {
                if (x < node->value)
                    node = node->left;
                else if (x > node->value)
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

        vector<_T> _inorder_iteration(){
            vector<_T> res;
            stack<_node*> s;
            _node *curr = root;
            while(curr || !s.empty()){
                while(curr){
                    s.push(curr);
                    curr = curr->left;
                }
                curr = s.top();
                s.pop();
                res.push_back(curr->value);
                curr = curr->right;
            }
            return res;
        }        

        void _preorder_rec(_node *node){
            if(node){
                cout << node->value << " ";
                _preorder_rec(node->left);
                _preorder_rec(node->right);
            }
        }

        vector<_T> _preorder_iteration(){
            vector<_T> res;
            stack<_node*> s;
            _node *curr = root;
            while(curr || !s.empty()){
                while(curr){
                    res.push_back(curr->value);
                    s.push(curr);
                    curr = curr->left;
                }
                curr = s.top();
                s.pop();
                curr = curr->right;
            }
            return res;
        }   

        void _postorder_rec(_node *node){
            if(node){
                _postorder_rec(node->left);
                _postorder_rec(node->right);
                cout << node->value << " ";
            }
        }

        vector<_T> _postorder_iteration(){
            vector<_T> res;
            stack<_node*> s;
            _node *curr = root;
            while(curr || !s.empty()){
                while(curr){
                    s.push(curr);
                    s.push(curr);
                    curr = curr->left;
                }
                curr = s.top();
                s.pop();
                if(!s.empty() && curr == s.top())
                    curr = curr->right;
                else{
                    res.push_back(curr->value);
                    curr = NULL;
                }    
            }
            return res;
        }

    public:
        void insert(_T val){
            if(!find(val)){
                root =  _rec_insert(val,root);
                _size++;
            }
            // _iterative_insert(val);
        }

        _node *find(_T val){
            return _find(root, val);
        }

        vector<_T> inorder(){
            // _inorder_rec(root);
            // cout << "\n";
            return _inorder_iteration();
        }

        vector<_T> preorder(){
            // _preorder_rec(root);
            // cout << "\n";
            return _preorder_iteration();
        }

        vector<_T> postorder(){
            // _postorder_rec(root);
            // cout << "\n";
            return _postorder_iteration();
        }

};

int main(){
    tree<int> mytree;
    int q;
    cin >> q;
    while(q--){
        int temp;
        cin >> temp;
        mytree.insert(temp);
    }
    int f;
    cin >> f;
    auto res = mytree.find(f);
    if (res){
        unsigned long long hasil = (res->height)*(res->height);
        if(hasil)
            cout << hasil << "0000" << endl;
        else
            cout << "0" << endl;
    } else
        cout << "0" << endl;
    return 0;
}