//用迭代,排列组合的问题。思路：遍历输入的字符串digits，取出对应的字母串，存入向量中，后存入的与前面的进行组合。
//如，对于示例，首先将2对应的[a],[b],[c]放入res中，然后与3对应的def组合，依次放入[ad],[ae],[af]...
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size()==0) return res;
        string dict[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        res.push_back("");
        for (int i=0;i<digits.size();i++){
            string str=dict[digits[i]-'2']; //取出数字对应的字母串
            int n=res.size();
            for (int j=0;j<n;j++){ //进行排列组合
                string tmp=res.front(); //从向量中取出第一个元素并删除
                res.erase(res.begin());
                for (int k=0;k<str.size();k++)
                    res.push_back(tmp+str[k]);
            }
        }
        
        return res;
    }
};
