class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> result;
        for (int i=0;i<nums.size();i++){
            int k=i+1;
            while(k<nums.size()+i){
                if (nums[k%nums.size()]>nums[i]){
                    result.push_back(nums[k%nums.size()]);
                    break;
                }
                k++;
            }
            if (k==nums.size()+i)
                result.push_back(-1);
        }
        return result;
    }
};
