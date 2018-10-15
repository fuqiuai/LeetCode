class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        if (strs.size()==0) return result; //特殊情况
        
        int maxLen=-1;
            for (int j=0;j<strs[0].size();j++){
                string subStr=strs[0].substr(0,j+1);
                //判断子串subStr是否是公共前缀
                bool flag=true;
                for (int k=1;k<strs.size();k++){
                    if (strs[k].find(subStr)!=0){
                        flag=false;
                        break;
                    }
                }
                //subStr是公共前缀
                if (flag){
                    int temp=subStr.size();
                    if (temp>maxLen){
                        maxLen=temp;
                        result=subStr;
                    }
                }
                //subStr不是公共前缀
                else break;
            }

        
        return result;
    }
};
