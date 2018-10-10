class Solution {
public:
    int nextGreaterElement(int n) {
        // 将n中每一位取出，转化成31. 下一个排列的题
        
        //第一步，将n每一位取出存入vector
        vector<int> nums;
        while(n){
            nums.push_back(n%10);
            n/=10;
        }
        reverse(nums.begin(),nums.end());
        
        //第二步，求下一个排列
        int pos=-1;
        for (int i=nums.size()-1;i>=1;i--){
            if (nums[i]>nums[i-1]){
                pos=i-1;
                break;
            }
        }
        if (pos!=-1){ //若pos==-1，则这是一个降序序列，表示不存在下一个更大元素
            for (int i=nums.size()-1;i>=pos+1;i--){ 
                if (nums[i]>nums[pos]){
                    swap(nums[i],nums[pos]);
                    break;
                }
            }
            reverse(nums.begin()+pos+1,nums.end()); 
        }
        else return -1;
        
        //第三步，从vector取出每一位转化成int型
        long int result=0;
        for (int i=0;i<nums.size();i++) result=result*10+nums[i];
        if (result>INT_MAX) return -1;
        return result;
    }
};
