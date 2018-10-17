// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         //方法1：暴力枚举
//         if (height.size()==2) return min(height[0],height[1]);
        
//         int result=INT_MIN;
//         for (int i=0;i<height.size();i++)
//             for (int j=height.size()-1;j>=0;j--){
//                 if (i>=j) break;
//                 result=max(result,(j-i)*min(height[i],height[j]))
//             }
//         return result;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        //方法2：双指针
        if (height.size()==2) return min(height[0],height[1]);
        
        int result=INT_MIN;
        int left=0,right=height.size()-1;
        while(left<right){
            result=max(result,(right-left)*min(height[left],height[right]));
            if (height[left]<height[right]) left++;
            else right--;
        }

        return result;
    }
};
