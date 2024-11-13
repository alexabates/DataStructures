#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool evaluateTree(TreeNode* root){
    //base case: if the node is a leaf node, return its value as a boolean
    if(root->val == 0){
        return false;
    } else if(root->val == 1){
        return true;
    }

    //recursively evaluate left and right subtrees
    bool leftEval = evaluateTree(root->left);
    bool rightEval = evaluateTree(root->right);

    //apply the boolean operation based on the current node's value
    if(root->val == 2){
        //OR operation
        return leftEval || rightEval;
    } else if(root->val == 3){
        //AND operation
        return leftEval && rightEval;
    }

    //this line should not be reachd if the tree is defined correctly
    return false;
};

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    bool result = evaluateTree(root);

    cout << "Result: " << result << endl;

    return 0;
}