class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<=2) return nums.size();//特殊情况
        int left=0;
        while(left<nums.size()-1){
            int right=0;
            for (int k=left+1;k<nums.size();k++){ //找到不同于当前值的位置，记录到right中
                if (nums[left]!=nums[k]){
                    right=k;
                    break;
                }
                if (k==nums.size()-1){
                    right=nums.size();
                    break;
                }  
            }            
            if (right-left>2) {nums.erase(nums.begin()+left+2,nums.begin()+right); left+=2;} //删除出现多于两次的数字
            else left=right;
        }
        
        return nums.size();
    }
};
