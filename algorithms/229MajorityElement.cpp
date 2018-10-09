class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*由于时间及空间限制，所以本题只能采用摩尔投票法（基于169. 求众数）；
        显然，超过 ⌊ n/3 ⌋ 次的元素最多有2个，因此在使用摩尔算法时，同时记录两个大多数，
        得到一个大多数，和一个出现次数仅次于大多数的数，最后检查它们出现的次数是否符合条件(https://www.hijerry.cn/p/45987.html)*/
        
        //摩尔投票法得到两个大多数
        vector<int> result;
        int result1, result2, score1=0, score2=0;
        for (int i=0;i<nums.size();i++){
            if (result1==nums[i]) score1++;
            else if (result2==nums[i]) score2++;
            else if (score1==0) {result1=nums[i];score1=1;}
            else if (score2==0) {result2=nums[i];score2=1;}
            else {score1--; score2--;}
        }
        
        // 统计两个大多数的出现次数
        int time1=0,time2=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==result1) time1++;
            else if (nums[i]==result2) time2++;
        }
        //得到结果
        if (time1>nums.size()/3) result.push_back(result1);
        if (time2>nums.size()/3) result.push_back(result2);
        return result;

    }
};
