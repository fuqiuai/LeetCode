class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //方法1：暴力枚举，时间复杂度O(n^2)。略
        
        //方法2：双指针，动态滑窗解决
        if (nums.size()==0) return 0;//特殊情况
        
        int left=0,right=0;//窗口起止位置
        int result=INT_MAX;
        int curSum=0;//当前窗口的和
        while(left<nums.size()){
            if (curSum<s){//(1)当前窗口的和没有达到s，则窗口向右滑一格
                curSum+=nums[right];
                right++;
            }
            if (curSum>=s){//(2)当前窗口的和达到了s，则窗口向左收缩一格
                result=min(result,right-left);                  
                curSum-=nums[left];
                left++;
            }
            if (curSum<s && right>=nums.size()) break; //(3)退出循环
        }
        
        return (result==INT_MAX)?0:result;
    }

};
