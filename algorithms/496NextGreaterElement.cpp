class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        
        vector<int> result;
        for (int i=0;i<findNums.size();i++){
            for (int j=0;j<nums.size();j++){
                if (findNums[i]==nums[j]){
                    int k=j+1;
                    while(k<nums.size()){
                        if (nums[k]>findNums[i]) {result.push_back(nums[k]); break;}
                        else k++;
                    }
                    if (k==nums.size()) result.push_back(-1);
                    break;
                }
            }
        }
        return result;
    }
};
