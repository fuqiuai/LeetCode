class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         在15. 三数之和的基础上，多加一重循环
        
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        
        for (int i=0;i<nums.size();i++)
            for (int j=i+1;j<nums.size();j++){
                if (nums[i]+nums[j]>target/2) break; //剪枝操作
                if (i>0 && nums[i]==nums[i-1]) continue; //去重操作
                if (j!=i+1 && nums[j]==nums[j-1]) continue;
                
                int left=j+1, right=nums.size()-1;
                while(left<right){
                    int sum=nums[i]+nums[j]+nums[left]+nums[right];
                    if (sum>target) right--; 
                    else if (sum<target) left++;
                    else{
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while (left<right && nums[left]==nums[left+1]) left++; //这两条语句是为了去重
                        while (left<right && nums[right]==nums[right-1]) right--;
                        left++;right--;
                    }
                }
            
            }

        return result;
    }
};
