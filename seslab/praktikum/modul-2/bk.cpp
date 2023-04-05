#include <bits/stdc++.h>
using namespace std;


template<typename _T>
struct tree{
private:
    typedef struct _node{
        _T value;
        int color;
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

    vector<_node*> _postorder_iteration(){
        vector<_node*> res;
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
                res.push_back(curr);
                curr = NULL;
            }    
        }
        return res;
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

    vector<_node*> postorder(){
        // _postorder_rec(root);
        // cout << "\n";
        return _postorder_iteration();
    }

    int color[3]={0,0,0};
    int getcolor(_node* node){
        return node->color;
    }

    void setcolor(_node* node, int color){
        node->color = color;
        this->color[color]++;
    }

    //0:NULL 1:RED 2:BLACK
    void coloring(){
        vector<_node*> arr = this->postorder();
        for(auto i = 0; i<arr.size(); i++){
            _node* node = arr[i];
            if(node->left && getcolor(node->left)==1){
                setcolor(node, 2);
            } else if(node->right && getcolor(node->right)==1){
                setcolor(node, 2);
            } else {
                setcolor(node,1);
            }
        }
    }

    void solve(){
        coloring();
        cout << this->color[1];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tree<int> mytree;
    int n;
    cin >> n;
    while(n--){
        int temp;
        cin >> temp;
        mytree.insert(temp);
    }
    mytree.solve();
    return 0;
}