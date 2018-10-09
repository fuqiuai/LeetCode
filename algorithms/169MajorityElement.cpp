class Solution {
public:
    int majorityElement(vector<int>& nums) {
// 解法1：因为这里的众数不是指出现次数最多的数，而是指数组中出现次数大于数组数量一半的元素，可以先将数组按升序顺序排序，找出数组中中间元素即可。 
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()/2];
        
        
// 解法2：用map容器
//         map<int, int> times;
//         for (int i=0;i<nums.size();i++)
//             times[nums[i]]++;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             if(times[nums[i]]>nums.size()/2) return nums[i];
//         }

// 解法3：摩尔投票法,核心思想是同加、异减 https://www.hijerry.cn/p/45987.html
        int result, score=0;
        for (int i=0;i<nums.size();i++){
            if (result==nums[i]) score++;
            else if (score==0) {result=nums[i];score=1;}
            else score--;
        }
        return result;
    }
};
