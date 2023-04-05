#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef struct _node{
    int value,gold;
    int mined;
    struct _node *left, *right, *parent;
} _node;
template<typename _T>
struct tree{
    private:
        
        _node *root = NULL;
        unsigned _size = 0;

        _node *_create_node(_T val,int gold, _node* parent){
            _node *newNode = (_node*)malloc(sizeof(_node));
            newNode -> value = val;
            newNode -> left = newNode -> right = NULL;
            newNode -> parent = parent;
            newNode ->gold = gold;
            newNode ->mined = 0;
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

        void _iterative_insert(_T val, int gold){
            if(root==NULL)
                root = _create_node(val,gold, NULL);
            else{
                _node *node= root;
                while(node){
                    if(val < node->value){
                        if(node->left)
                            node = node->left;
                        else{
                            node->left = _create_node(val,gold,node); 
                            break;
                        }
                    } else if(val > node->value)
                        if(node->right)
                            node = node->right;
                        else{
                            node->right = _create_node(val,gold,node); 
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
        _node *pos=NULL;
        void insert(_T val, int gold){
            // if(!find(val)){
                // root =  _rec_insert(val,root);
                // _size++;
            // }
            _iterative_insert(val, gold);
            if(!pos)
                pos=root;
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
    int q;
    tree<int> mytree;
    long long e_scan, e_move, e_mine, tot_gold, tot_room;
    e_scan = e_move = e_mine = tot_gold = tot_room = 0;
    cin >> q;
    while(q--){
        string str;
        cin >> str;
        // cout << str << endl;
        if(str=="SCAN"){
            int c;
            cin >> c;
            while(c--){
                int temp, gold;
                cin >> temp >> gold;
                if(mytree.find(temp))
                    e_scan++;
                else {
                    mytree.insert(temp,gold);
                    tot_room++;
                }
            }
        } else if(str=="MOVE"){
            cin >> str;
            if(str=="UP"){
                if(mytree.pos && mytree.pos -> parent){
                    mytree.pos = mytree.pos->parent;
                } else
                    e_move++;
            } else if(str=="LEFT"){
                if(mytree.pos && mytree.pos -> left){
                    mytree.pos = mytree.pos->left;
                } else
                    e_move++;
            } else if(str=="RIGHT"){
                if(mytree.pos && mytree.pos -> right){
                    mytree.pos = mytree.pos->right;
                } else
                    e_move++;
            } 
        } else{
            if(mytree.pos->mined){
                e_mine++;
            } else {
                tot_gold += mytree.pos->gold;
                mytree.pos->mined=1;
            }
        }
    }
    cout << "ERROR MOVE: " << e_move << endl;
    cout << "ERROR MINE: " << e_mine << endl;
    cout << "ERROR SCAN: " << e_scan << endl;
    cout << "TOTAL GOLD: " << tot_gold << endl;
    cout << "TOTAL ROOM: " << tot_room << endl;
    return 0;
}