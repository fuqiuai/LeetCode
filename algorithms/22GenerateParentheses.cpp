//用递归,排列组合的问题
class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        generate(0,0,"",n);
        return res;
    }
private:
    void generate(int left,int right,string s,int n){ //left right分别表示左括号和右括号的个数
        if (right==n) res.push_back(s);
        else{
            if (left<n) generate(left+1,right,s+"(",n);
            if (right<left) generate(left,right+1,s+")",n);
        }
    }
};
