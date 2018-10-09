class Solution {
//     思路：（1）从右边起找到第一个升序对，即a[i-1]<a[i] 
//           （2）将a[i-1]与右边最后一个比它大的数a[j]交换 
//           （3）反转a[i-1]后的子序列
public:
    void nextPermutation(vector<int>& nums) {
        
        // 第一步
        int pos=-1;
        for (int i=nums.size()-1;i>=1;i--){
            if (nums[i]>nums[i-1]){
                pos=i-1;
                break;
            }
        }
        //第二步
        if (pos!=-1){ //若pos==-1，则这是一个降序序列，跳过第二步
            for (int i=nums.size()-1;i>=pos+1;i--){
                if (nums[i]>nums[pos]){
                    swap(nums[i],nums[pos]);
                    break;
                }
            }
        }
        //第三步
        reverse(nums,pos);
        
    }

private:
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
private:
    void reverse(vector<int>& vec, int k){
        int i=k+1,j=vec.size()-1;
        while (i<j){
            swap(vec[i],vec[j]);
            i++;
            j--;
        }
    }
};
