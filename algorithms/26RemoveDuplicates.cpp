class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        for (int i=0;i<nums.size();i++)
            for (int j=i+1;j<nums.size();j++){
                if (nums[i]!=nums[j]){
                    nums.erase(nums.begin()+i+1,nums.begin()+j);
                    break;
                }
                if (j==nums.size()-1){
                    nums.erase(nums.begin()+i+1,nums.end());
                    break;
                }
            }
        
        return nums.size();
    }
};
