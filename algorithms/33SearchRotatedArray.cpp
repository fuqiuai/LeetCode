class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 二分查找。二分查找法的关键在于获得了中间数后，判断下面要搜索左半段还是右半段
        // 此序列的规律在于，如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的。
        // 因此我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了
        
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]<nums[right]){
                if (nums[mid]<target && target<=nums[right]) left=mid+1;
                else right=mid-1;
            }
            else{
                if (nums[left]<=target && target<nums[mid]) right=mid-1;
                else left=mid+1;
            }
        }
        
        return -1;
    }
};
