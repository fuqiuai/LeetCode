// //方法1：递归回溯
// class Solution {
//     vector<vector<int>> res;
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         if (nums.size()==0) return res;
//         permuteMain(nums,0);
//         return res;
//     }
// private:
//     void permuteMain(vector<int> nums, int begin){
//         if (begin==nums.size()) res.push_back(nums);
//         else{
//             for (int i=begin;i<nums.size();i++){
//                 swap(nums[begin],nums[i]);
//                 permuteMain(nums,begin+1);
//                 swap(nums[begin],nums[i]);
//             }
//         }
//     }
// };
//方法2：调用库函数next_permutation

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        do  
        {  
            res.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end())); 
        return res; 
    }
};
