/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//广度优先（层次）遍历，使用队列实现
//具体思路：在访问了一个节点之后，它的子节点（如果有的话）按照从左到右的顺序一次放入队列的末尾，然后访问该队列头部的节点，被访问过的节点从队列中出队，直至队列为空
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        
        return res;
    }
};
