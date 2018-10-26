/*方法1：暴力法。选出所有子字符串可能的开始和结束位置，并检验它是不是回文，时间复杂度为O(n^3)。
方法2：动态规划。时间复杂度为O(n^2)
（1）优化函数：求len(dp[i][j])的最大值
dp[i][j]=true，如果以i开始以j结束的子串是回文子串
dp[i][j]=false ，其他情况
（2）状态转移方程：dp[i][j]=(dp[i+1][j−1] and S_i==S_j})
初始化:长度为1和2的回文*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size()<=1) return s;
        
        bool dp[1001][1001]={false};
        int maxSublen=1, start=0;
        //初始化dp
        for (int i=0;i<s.size();i++){
            dp[i][i]=true;
            if (i<s.size()-1 && s[i]==s[i+1]){
                dp[i][i+1]=true;
                maxSublen=2;
                start=i;
            }
        }
        //dp转移
        for (int len=3;len<=s.size();len++){//len表示子串长度
            for (int i=0;i<=s.size()-len;i++){
                dp[i][i+len-1]=(dp[i+1][i+len-2] && (s[i]==s[i+len-1]));
                if (dp[i][i+len-1]){
                    maxSublen=len;
                    start=i;
                }
            }
        }
        //得到结果
        return s.substr(start,maxSublen);
    }
};
