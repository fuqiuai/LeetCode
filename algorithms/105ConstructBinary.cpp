/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//思路：(1)前序遍历中的第一个节点为当前树的根节点；(2)在中序序列中找到当前根节点；(3)算出左子树和右子树的节点个数；(4)最后递归构建左右子树
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);        
    }
private:
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
        if (pre_left>pre_right || in_left>in_right) return NULL;
        int rootVal=preorder[pre_left]; // (1)前序遍历中的第一个节点为当前树的根节点
        TreeNode* root=new TreeNode(rootVal);
        int index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), rootVal)); // (2)在中序序列中找到当前根节点
        int left_num=index-in_left; // (3)算出左子树和右子树的节点个数
        int right_num=in_right-index;
        root->left=createTree(preorder,inorder,pre_left+1,pre_left+left_num,in_left,index-1); // (4)最后递归构建左右子树
        root->right=createTree(preorder,inorder,pre_left+left_num+1,pre_right,index+1,in_right);
        return root;
    }
};
