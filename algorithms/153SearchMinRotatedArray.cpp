class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int min=INT_MAX;
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if (nums[mid]<nums[right]){
                if (nums[mid]<min) min=nums[mid];
                right=mid-1;
            }
            else{
                if (nums[left]<min) min=nums[left];
                left=mid+1;
            }
        }
        
        return min;
    }
};
