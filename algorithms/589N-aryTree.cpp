/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    vector<int> res;
public:
    vector<int> preorder(Node* root) {
        if (root){
            res.push_back(root->val);
            for(int i=0;i<root->children.size();i++)
                preorder(root->children[i]);
        }
        return res;
    }
};
