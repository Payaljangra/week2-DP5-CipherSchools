#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sorted(nums,0,nums.size()-1);
    }
    TreeNode* sorted(vector<int>& nums, int left, int right){
    if(left > right)
        return NULL;
    int mid = left + (right-left)/2;
    TreeNode* temp = new TreeNode(nums[mid]);
    temp->left = sorted(nums,left,mid-1);
    temp->right = sorted(nums,mid+1, right);
    return temp;    
}
int main()
{
    
}