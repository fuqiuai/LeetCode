class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());//排序
        
        return nums[nums.size()-k];
    }
};
