/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return createTree(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);        
    }
private:
    TreeNode* createTree(vector<int>& postorder, vector<int>& inorder, int post_left, int post_right, int in_left, int in_right) {
        if (post_left>post_right || in_left>in_right) return NULL;
        int rootVal=postorder[post_right]; // (1)后续遍历中的最后一个节点为当前树的根节点
        TreeNode* root=new TreeNode(rootVal);
        int index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), rootVal)); // (2)在中序序列中找到当前根节点
        int left_num=index-in_left; // (3)算出左子树和右子树的节点个数
        int right_num=in_right-index;
        root->left=createTree(postorder,inorder,post_left,post_left+left_num-1,in_left,index-1); // (4)最后递归构建左右子树
        root->right=createTree(postorder,inorder,post_left+left_num,post_right-1,index+1,in_right);
        return root;
    }
};
