class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // 在33. 搜索旋转排序数组的基础上,判断right和mid的值相等的情况 
        
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)>>1;
            if (nums[mid]==target) return true;
            
            else if (nums[mid]<nums[right]){
                if (nums[mid]<target && target<=nums[right]) left=mid+1;
                else right=mid-1;
            }
            else if (nums[mid]>nums[right]){
                if (nums[left]<=target && target<nums[mid]) right=mid-1;
                else left=mid+1;
            }
            else
                right--;
        }
        
        return false;
    }
};
