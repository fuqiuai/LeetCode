/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//二叉树的层次遍历
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> vecAvg;
        if(!root) return vecAvg;
        
        //层次遍历结果放入res中
        vector<vector<int>> res;
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
        //对每一层节点求平均值
        for (int i=0;i<res.size();i++){
            double avg=0;
            for (int j=0;j<res[i].size();j++)
                avg+=res[i][j];
            avg/=res[i].size();
            vecAvg.push_back(avg);
        }
        return vecAvg;
        
    }
};
