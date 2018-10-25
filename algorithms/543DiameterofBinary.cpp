/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//利用递归，对每一个根节点，计算其左边的深度和右边的深度，
//左右深度相加即为当前子树的直径，遍历完每一棵子树后最大的那个直径即为二叉树的直径。
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        depth(root,res);
        return res;
    }
private:
    int depth(TreeNode *root,int &res){
        if (!root) return 0;
        int left_depth=depth(root->left,res);
        int right_depth=depth(root->right,res);
        res=max(res,right_depth+left_depth);
        return max(left_depth+1,right_depth+1);
    }
};
