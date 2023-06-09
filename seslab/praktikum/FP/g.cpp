#include <bits/stdc++.h>
using namespace std;

typedef struct _node{
    int value;
    struct _node *left, *right;
} _node;
template<typename _T>
struct tree{
    private:
        
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

        void _iterative_insert(_T val){
            if(root==NULL)
                root = _create_node(val);
            else{
                _node *node= root;
                while(node){
                    if(val < node->value){
                        if(node->left)
                            node = node->left;
                        else{
                            node->left = _create_node(val); 
                            break;
                        }
                    } else if(val > node->value)
                        if(node->right)
                            node = node->right;
                        else{
                            node->right = _create_node(val); 
                            break;
                        }
                    else
                        return;
                }
            }
            _size++;
        }

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

        vector<_node*> _inorder_iteration(){
            vector<_node*> res;
            stack<_node*> s;
            _node *curr = root;
            while(curr || !s.empty()){
                while(curr){
                    s.push(curr);
                    curr = curr->left;
                }
                curr = s.top();
                s.pop();
                res.push_back(curr);
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
        _node* __findMinNode(_node *node) {
            _node *currNode = node;
            while (currNode && currNode->left != NULL)
                currNode = currNode->left;
            
            return currNode;
        }
        _node* __remove(_node *node, int value) {
            if (node == NULL) return NULL;

            if (value > node->value) 
                node->right = __remove(node->right, value);
            else if (value < node->value) 
                node->left = __remove(node->left, value);
            else {

                if (node->left == NULL) {
                    _node *rightChild = node->right;
                    free(node);
                    return rightChild;
                }
                else if (node->right == NULL) {
                    _node *leftChild = node->left;
                    free(node);
                    return leftChild;
                }

                _node *temp = __findMinNode(node->right);
                node->value     = temp->value;
                node->right   = __remove(node->right, temp->value);
            }
            return node;
        }

    public:
        void insert(_T val){
            // if(!find(val)){
                // root =  _rec_insert(val,root);
                // _size++;
            // }
            _iterative_insert(val);
        }

        _node *find(_T val){
            return _find(root, val);
        }

        vector<_node*> inorder(){
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

        void remove(int value) {
            if (find(value)) {
                root = __remove(root, value);
                // _size++;
            }
        }

};

int main(){
    tree<int> mytree;
    int n,x,cmd;
    cin >> n;
    while(n--){
        cin >> cmd;
        if(cmd == 15){
            cin >> x;
            mytree.insert(x);
        } else if(cmd == 04){
            cin >> x;
            mytree.remove(x);
        } else {
            bool f = true;
            vector<_node*> temp = mytree.inorder();
            for(_node* i:temp){
                if((i->left && !i->right) ||
                    (!i->left && i->right)){
                    cout << i->value << " ";
                    f = false;
                }
            }
            if(f) 
                cout << "Use whatever means you must to control our population. Just do it.";
            cout << endl;
        }
    }
    return 0;
}