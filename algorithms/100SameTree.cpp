/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 递归算法 
// 1.判断两个二叉树是否为空，若均为空则返回true，若只有一个为空则返回false 
// 2.两个二叉树均不为空。 如果根节点具有相同的值并且根的左子树是相同的（递归）和根的右子树是相同的（递归）返回true，否则返回false。

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true; //两棵树都为空返回true
        if ((p && !q) || (!p && q)) return false; //只有一棵树为空返回false
        if (p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right)) return true; //节点值相同，且左右子树都相同
        else return false;
    }
};
