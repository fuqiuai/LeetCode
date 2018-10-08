class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//         方法1：
//         for (int i=0;i<nums.size();i++){
//             for (int j=i+1;j<nums.size();j++){
//                 if (nums[i]+nums[j]==target){
//                     return {i,j};
//                 }
                
//             }
//         }
        
       // 方法2：利用map
        vector<int> result;
        map<int, int> map1;
        for (int i=0;i<nums.size();i++)
            map1[nums[i]]=i;
        
        for (int i=0;i<nums.size();i++){
            if (map1.count(target-nums[i])==1 && i!=map1[target-nums[i]]){
                result.push_back(i);
                result.push_back(map1[target-nums[i]]);
                break;
            }
        }
        return result;
            
    }
};
