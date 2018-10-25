/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//思路：根据树的结构特点，将其分为左子树和右子树两部分，根据递归先序遍历的思想将大问题转化为小问题，左右子树中深度最大的一棵即为该树结构的深度。
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int leftDepth=maxDepth(root->left);
        int rightDepth=maxDepth(root->right);
        return max(leftDepth,rightDepth)+1;
    }
};
