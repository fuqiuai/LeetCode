class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
//         首先从小到大排序，然后遍历数组中每一个元素，用双指针找到另外两个元素,将三元组存入vector中（注意在此过程中要去重）
        
        vector<vector<int>> result;
        // 1.排序
        sort(nums.begin(),nums.end());
        
        // 2.找到三元组
        for (int i=0;i<nums.size();i++){
            if (nums[i]>0) break; //剪枝操作，如果当前数大于0则break
            if (i>0 && nums[i]==nums[i-1]) continue; //去重操作
            
            int left=i+1, right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if (sum>0) right--; 
                else if (sum<0) left++;
                else{
                    result.push_back({nums[i],nums[left],nums[right]});
                    while (left<right && nums[left]==nums[left+1]) left++; //这两条语句是为了去重
                    while (left<right && nums[right]==nums[right-1]) right--;
                    left++;right--;
                }
            }
            
        }

        return result;
    }
};
