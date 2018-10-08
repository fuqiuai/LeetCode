class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());//升序排序
        int min=INT_MAX;       
        int result=0;

        for (int i=0;i<nums.size();i++){
            int left=i+1, right=nums.size()-1;
            while (left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if (abs(sum-target)<min){
                    min=abs(sum-target);
                    result=sum;
                }
                if (sum>target) right--;
                else if (sum<target) left++;
                else return sum;
            }  
        }
        
        return result;
    }
};
