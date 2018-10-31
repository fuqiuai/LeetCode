//动态规划,复杂度为 O(n): 令dp[i]表示最后一项为nums[i]的序列构成的最大子序和，则递推关系为
//dp[i+1]=max(dp[i]+nums[i+1],nums[i+1]);目标求max(dp[i]);
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp=nums[0];
        int res=nums[0];
        for (int i=1;i<nums.size();i++){
            dp=max(dp+nums[i],nums[i]);
            res=max(res,dp);
        }
            
        return res;
    }
};
