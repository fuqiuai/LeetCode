/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//按中序遍历后，看得到的结果是否是递增的
class Solution {
    vector<int> res;
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        res=inorderTraversal(root);
        for (int i=0;i<res.size()-1;i++)
            if (res[i]>=res[i+1])
                return false;
        return true;
    }
private:
    vector<int> inorderTraversal(TreeNode* root) {
        //中序遍历
        if (root){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }    
};
