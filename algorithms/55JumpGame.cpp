class Solution {
public:
    bool canJump(vector<int>& nums) {
        //贪心算法。贪心策略：假设当前位置为i,在位置i能跳到的位置里选取使得下一步跳跃能达到最远的那个位置
        if (nums.size()<=1) return true;
        int pos=0;
        while(pos<nums.size()){
            if (nums[pos]==0 && pos!=nums.size()-1) return false;
            if (pos==nums.size()-1) return true;
            int max=INT_MIN, k=pos; //选取下一个跳跃点
            for (int i=k+1;i<=k+nums[k] && i<nums.size();i++){
                if (nums[i]+i>max){
                    pos=i;
                    max=nums[i]+i;
                }
            }        
        }
        return false;
    }
};
