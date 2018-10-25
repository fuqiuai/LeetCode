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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*> nodeQueue;//保存节点的队列
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            int size=nodeQueue.size();
            vector<int> resTemp;
            while(size--){
                TreeNode* pointer=nodeQueue.front();//读取队首节点
                resTemp.push_back(pointer->val);//访问当前节点
                nodeQueue.pop();//将访问过的节点移除队列
                if (pointer->left) nodeQueue.push(pointer->left);//将访问过的节点的左右孩子节点依次加入至队尾
                if (pointer->right) nodeQueue.push(pointer->right);           
            }
            res.push_back(resTemp);
        }
        
        reverse(res.begin(),res.end());//与102. 二叉树的层次遍历一模一样，唯一的不同是最后反转即可
        return res;
    }
};
