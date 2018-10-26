/*动态规划,用dp[i][j]表示si...sj的最长回文子序列，求dp[0][n-1]
递推公式为：
如果s[i]==s[j]， dp[i][j]=dp[i+1][j-1]+2
不然，dp[i][j]=max(dp[i+1][j],dp[i][j-1])
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[1001][1001]={0};
        //初始化dp
        for (int i=0;i<s.size();i++)
            dp[i][i]=1;     
        //转移dp
        for (int j=1;j<s.size();j++){
            for (int i=j-1;i>=0;i--){
                if (s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }            
        }
        //得到结果
        return dp[0][s.size()-1];
    }
};
