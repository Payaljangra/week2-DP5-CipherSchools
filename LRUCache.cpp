class Node{//doubly circular ll
public:
    int key;
    int val;
    Node *left;
    Node *right;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        left=right=this;
    }
};
class LRUCache {
private:
    unordered_map<int,Node*> mp;
    Node *root{};
    int cap;
    int size{};
public:
    LRUCache(int capacity) {
        this->cap=capacity;
    }
    int get(int key) {
        auto itr=mp.find(key);
        if(itr==mp.end()){
            return -1;
        }
        Node *node=itr->second;
        if(root!=node){
            Node *lft=node->left;
            lft->right=node->right;
            node->right->left=lft;
            addFront(node);
        }
        return root->val;
    }
    void put(int key, int value) {
        auto itr=mp.find(key);
        if(itr==mp.end()){
            Node *temp=new Node{key,value};
            mp[key]=temp;
            size++;
            addFront(temp);
        }else{
            Node *node=itr->second;
            node->val=value;
            if(root!=node){
                Node *lft=node->left;
                lft->right=node->right;
                node->right->left=lft;
                addFront(node);
            } 
        }
        if(size>cap){
            deleteLast();
            size--;
        }
    }
    void addFront(Node *node){
            if(!root){
                root=node;
                return;
            }
            Node *lft=root->left;
            lft->right=node;
            node->left=lft;
            node->right=root;
            root->left=node;
            root=node;
    }
    void deleteLast(){
        if(root==root->left){
            mp.erase(root->key);
            root=NULL;
            delete root;
            return;
        }
        Node *del=root->left;
        del->left->right=root;
        root->left=del->left;
        mp.erase(del->key);
        delete del;
    }
};

