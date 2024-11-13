#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

int getHeight(TreeNode* root){
    //base case: if the node is null, return -1
    if(root == nullptr){
        return -1;
    }

    //recursively find the height of the left and right subtrees
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    //return the maximum of the two heights
    return max(leftHeight, rightHeight) + 1;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    int height = getHeight(root);

    cout << "Height of tree: " << height << endl;

    return 0;
}