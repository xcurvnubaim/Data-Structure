#include <bits/stdc++.h>
using namespace std;

typedef struct _node{
    unsigned value;
    struct _node *left, *right;
} _node;

map<unsigned,vector<_node*>> level;
// vector<int> out;


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
            // if(!find(val)){
                // root =  _rec_insert(val,root);
                // _size++;
            // }
            _iterative_insert(val);
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
        void fill_level(_node* node, int idx){
            level[idx].push_back(node);
            if(node->left)
                fill_level(node->left, idx+1);
            if(node->right)
                fill_level(node->right, idx+1);
        }

        void solve(){
            if(root){
                fill_level(root,0);
            }
        }
};

int main(){
    tree<unsigned> mytree;
    unsigned x;
    // cin >> n;
    while(cin >> x){
        mytree.insert(x);
    }
    mytree.solve();
    // for(int i=2; level[i+1].size(); i++){
    //     for(int j=1; j<level[i].size()-1; j++){
    //         if(level[i][j]->left || level[i][j]->right)
    //             out.push_back(level[i][j]->value);
    //     }
    // }

    // if(out.size()){
    //     sort(out.begin(), out.end());
    //     for(auto i=out.begin(); i!=out.en            d(); i++)
    //         cout << *i << " ";
    // } else {
    //     cout << "Strategi Syulit";
    // }
    // unsigned maxlev=0;
    
    for(unsigned i=0; level.find(i)!=level.end(); i++){
        cout << level[i].back()->value << endl;
        // maxlev=i;
    }
    
    return 0;
}