class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        # 有两种方法，一种是第1题中方法2，时间空间复杂度均为O(n)；
        # 另一种用双指针，时间复杂度为O(n),空间复杂度为O(1)。这里用第二种方法实现
        vector<int> result;
        int left=0;
        int right=numbers.size()-1;
        while (left<right){
            int sum=numbers[left]+numbers[right];
            if (sum==target){
                result.push_back(left+1);
                result.push_back(right+1);
                break;
            }
            else if (sum>target)
                right--;
            else
                left++;
        }
        
        return result;
    }
};

