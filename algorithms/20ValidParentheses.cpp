class Solution {
public:
    bool isValid(string s) {
        // 用栈实现
        
        stack<char> p;
        p.push('#'); //加一个“哨兵”，避免空栈的判断
        for (int i=0;i<s.size();i++){
            if (s[i]==')'){
                if (p.top()=='(') p.pop();
                else return false;
            }
            else if (s[i]==']'){
                if (p.top()=='[') p.pop();
                else return false;
            }
            else if (s[i]=='}'){
                if (p.top()=='{') p.pop();
                else return false;
            }
            else p.push(s[i]);
        }
        
        if (p.size()==1) return true;
        else return false;
    }
};
