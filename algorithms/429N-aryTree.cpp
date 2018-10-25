/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<Node*> nodeQueue;//保存节点的队列
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            int size=nodeQueue.size();
            vector<int> resTemp;
            while(size--){
                Node* pointer=nodeQueue.front();//读取队首节点
                resTemp.push_back(pointer->val);//访问当前节点
                nodeQueue.pop();//将访问过的节点移除队列
                for (int i=0;i<pointer->children.size();i++)//将访问过的节点的孩子节点从左到右依次加入至队尾
                    nodeQueue.push(pointer->children[i]);           
            }
            res.push_back(resTemp);
        }
        
        return res;        
    }
};
