class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //找出第一大和第二大的数，并标记这些数，在剩下的数中寻找最大的数就是整个序列的第三大数
        if (nums.size()==1) return nums[0];
        if (nums.size()==2) return max(nums[0],nums[1]);
        
        vector<bool> flag(nums.size(),true);
        
        int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
        for (int i=0;i<nums.size();i++){ //找第一大
            if (nums[i]>max1)
                max1=nums[i];
        }
        for (int i=0;i<nums.size();i++){ 
            if (nums[i]==max1)
                flag[i]=false;
        }
        for (int i=0;i<nums.size();i++){ //找第二大
            if (nums[i]>max2 && flag[i])
                max2=nums[i];
        }
        for (int i=0;i<nums.size();i++){ 
            if (nums[i]==max2)
                flag[i]=false;
        }
        
        bool ff=true;
        for (int i=0;i<nums.size();i++){ //找第三大
            if (nums[i]>=max3 && flag[i]){
                max3=nums[i];
                ff=false;
            }
        }
        
        if (ff) return max1;
        return max3;
        
    }
};
