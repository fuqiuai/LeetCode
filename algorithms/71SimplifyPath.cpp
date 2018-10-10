class Solution {
public:
    string simplifyPath(string path) {
//        用栈操作。首先按照“/”将地址进行分割，对分割出的子串进行不同的操作：
//        1、如果是空或者“.”,那么当前没有什么地址变动，地址栈不需要变动 
//        2、如果是“..” 则需要出栈（如果栈为空则不操作)因为这是返回上级目录的符号 
//        3、其他情况压栈
        
        string result;
        stack<string> p; 

        while(!path.empty()){
            int start=path.find("/");
            path=path.substr(start+1);
            int end=path.find("/");
            if (end==-1) end=path.length();
            string part=path.substr(0,end); //找到‘/’与‘/’中间的子串
            path=path.substr(end);

            
            if (part=="." || part=="") continue; //第一种情况
            else if (part==".."){ //第二种情况
                if (p.empty()) continue;
                p.pop();
            } 
            else p.push(part); //第三种情况
        }
        
        
        while (!p.empty()){
            result="/"+p.top()+result;
            p.pop();
        }
        if (result.empty()) result="/";
        return result;
    }
};
