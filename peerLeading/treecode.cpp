//trees
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left;
        TreeNode *right;

        //constructor
        TreeNode(int value) : data(value), left(nullptr), right(nullptr){}
};

class Tree{
    private:
        TreeNode *root;

        void dfsHelper(TreeNode *node) const;
        int countLeafNodesHelper(TreeNode *node) const;

    public:
        //constructor
        Tree();

        void setRoot(int value);
        TreeNode* getRoot() const;
        void addLeftchild(TreeNode *parent, int value);
        void addRightChild(TreeNode *parent, int value);

        void preOrderTraversalHelper(TreeNode* node) const;
        void preOrderTraversal() const;

        void postOrderTraversalHelper(TreeNode *node) const;
        void postOrderTraversal() const;

        void inOrderTraversalHelper(TreeNode *node) const;
        void inOrderTraversal() const;

        void bfs() const;

        int countLeafNodes() const;
        ~Tree();
}; 

//construction
Tree :: Tree() : root(nullptr){}

//setting the root
void Tree :: setRoot(int value){
    root = new TreeNode(value);
}

//returning the pointer to the root
TreeNode* Tree :: getRoot() const{
    return root;
}

void Tree :: addLeftchild(TreeNode *parent, int value){
    if(parent->left){
        cout << "Left child already exists" << endl;
        return;
    }
    if(parent != nullptr){
        parent->left = new TreeNode(value);
    }
}

void Tree :: addRightchild(TreeNode *parent, int value){
    if(parent->right){
        cout << "Right child already exists" << endl;
        return;
    }
    if(parent != nullptr){
        parent->right = new TreeNode(value);
    }
}

void Tree :: preOrderTraversalHelper(TreeNode *node) const{
    if (node == nullptr){
        return;
    }
    cout << node->data << " ";
    preOrderTraversalHelper(node->left);
    preOrderTraversalHelper(node->right);
}

void Tree :: preOrderTraversal() const{
    cout << "This is preorder: ";
    preOrderTraversalHelper(root);
    cout << end;
}

void Tree :: postOrderTraversalHelper(TreeNode *node) const{
    if(node == nullptr){
        return;
    }

    postOrderTraversalHelper(node->left);
    postOrderTraversalHelper(node->right);

    cout << node->data << " ";
}

void Tree :: postOrderTraversal() const{
    cout << "This is post order: ";

    postOrderTraversalHelper(root);
    cout << endl;
}

void Tree :: inOrderTraversalHelper(TreeNode *node) const{
    if(node == nullptr){
        return;
    }

    inOrderTraversalHelper(node->left);
    cout << node->data << " ";
    inOrderTraversalHelper(node->right);
    
}

void Tree :: inOrderTraversal()const {
    cout << "This is in order: ";
    
    inOrderTraversalHelper(root);
    cout << endl;
}

void Tree :: bfs() const{
    //breadth first search
    if(root == nullptr){
        return;
    }

    queue<TreeNode*> q;
    
    q.push(root);
    cout << "BFS Traversal: ";

    while(!q.empty()){
        TreeNode *current = q.front();
        q.pop();

        cout << current->data << " ";
        if(current->left){
            q.push(current->left);
        }
        if(current->right){
            q.push(current->right);
        }
    }
    cout << endl;
}

void Tree :: countLeafNodesHelper(TreeNode *node) const{
    if(node == nullptr){
        return 0;
    }
    if(node->left == nullptr && node->right == nullptr){
        return 1;
    }

    return countLeafNodesHelper(node->left) + countLeafNodesHeler(node->right);
}

int Tree :: countLeafNodes() const{
    return countLeafNodesHelper(root);
}

Tree :: ~Tree(){
    delete root;
}

