class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //思路：通过建立一个栈，存储数字，当碰到运算符时，每次弹出两个运算，将结果再压入栈中。
        if (tokens.size()==0) return 0;
        if (tokens.size()==1) return stoi(tokens[0]);
        
        stack<int> st;
        for (int i=0;i<tokens.size();i++){
            if (tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*"  || tokens[i]=="/"){
                int num1=st.top();st.pop();
                int num2=st.top();st.pop();
                if (tokens[i]=="+") st.push(num2+num1);
                if (tokens[i]=="-") st.push(num2-num1);
                if (tokens[i]=="*") st.push(num2*num1);
                if (tokens[i]=="/") st.push(num2/num1);
            }            
            else
                st.push(stoi(tokens[i])); //stoi函数用于string转int
                
        }
        return st.top();
    }
};
