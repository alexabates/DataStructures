#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution {
    public:
        int totalTilt;

        Solution() : totalTilt(0) {} //constructor to initialize totalTilt

        int order(TreeNode* root){
            if(root == nullptr){
                return 0;
            }

            //calculate the sums of the left and right subtrees
            int leftSum = order(root->left);
            int rightSum = order(root->right);

            //calculate the tilt of the current node
            int tilt = abs(leftSum - rightSum);

            //update the total tilt
            totalTilt += tilt;

            //return the sum of values under this node
            return leftSum + rightSum + root->val;
        }

        int findTilt(TreeNode* root){
            totalTilt = 0; //reset totalTilt
            order(root); //start the recursion
            return totalTilt;
        }    
};

int main(){
    Solution solution;

    //Test case 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    cout << "Test case 1 output: " << solution.findTilt(root1) << endl;

    //Test case 2
    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(9);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(5);
    root2->right->right = new TreeNode(7);
    cout << "Test case 2 output: " << solution.findTilt(root2) << endl;

    return 0;
}