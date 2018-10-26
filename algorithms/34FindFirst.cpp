//使用分治算法，进行二分查找
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {   
        
        int l=0,r=nums.size()-1; //二分查找
        int pos=-1;
        while(l<=r){
            int m=(l+r)/2;
            if (nums[m]>target) r=m-1;
            else if (nums[m]<target) l=m+1;
            else { pos=m; break;}
        }
        
        if (pos==-1) return {-1,-1}; //没找到
        
        int start=pos,end=pos; //找到了，则往前和往后分别找到起始位置
        while(start>=0 && nums[start]==target) start--;
        while(end<=nums.size()-1 && nums[end]==target) end++;
        return {start+1,end-1};
    }
};
