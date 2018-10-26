//基于5. 最长回文子串
class Solution {
public:
    int countSubstrings(string s) {
        if (s.size()==0) return 0;
        
        bool dp[1001][1001]={false};
        int num=0;
        //初始化dp
        for (int i=0;i<s.size();i++){
            dp[i][i]=true;num++;
            if (i<s.size()-1 && s[i]==s[i+1]){
                dp[i][i+1]=true;
                num++;
            }
        }
        //dp转移
        for (int len=3;len<=s.size();len++){//len表示子串长度
            for (int i=0;i<=s.size()-len;i++){
                dp[i][i+len-1]=(dp[i+1][i+len-2] && (s[i]==s[i+len-1]));
                if (dp[i][i+len-1]){
                    num++;
                }
            }
        }
        //得到结果
        return num;        
    }
};
