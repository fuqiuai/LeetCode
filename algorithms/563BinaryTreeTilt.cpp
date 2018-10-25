/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//用递归，方法类似于543. 二叉树的直径
class Solution {
public:
    int findTilt(TreeNode* root) {
        int slope=0;
        nodeSum(root,slope);
        return slope;
    }
private:
    int nodeSum(TreeNode* root,int &slope){
        if (!root) return 0;
        int left_nodeSum=nodeSum(root->left,slope);
        int right_nodeSum=nodeSum(root->right,slope);
        slope+=abs(left_nodeSum-right_nodeSum);
        return root->val+left_nodeSum+right_nodeSum;
    }
};
