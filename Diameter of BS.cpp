#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1+ max(leftHeight , rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int opt1 = diameterOfBinaryTree(root->left);
        int opt2 = diameterOfBinaryTree(root->right);
        int opt3 = height(root->left)+height(root->right);

        int result = max(opt1, max(opt2,opt3));
        return result;
    }
int main(){
    
}      