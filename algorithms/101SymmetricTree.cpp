/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//思路：将二叉树分割为左子树和右子树，再判断两棵树是否对称
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isDui(root->left,root->right);
    }
private:
    bool isDui(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true; //两棵树都为空返回true
        if ((p && !q) || (!p && q)) return false; //只有一棵树为空返回false
        if (p->val==q->val && isDui(p->left,q->right) && isDui(p->right,q->left)) return true;//节点值相等，且左右子树分别对称，则返回true
        else return false;
    }
};
