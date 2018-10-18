class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 思路：(1)用一个result，设初值为0，保存最大利润 (2)扫一遍数组，让相邻的两个数相减，若差值大于0，则加到result上去

        if (prices.size()<=1) return 0;
        int result=0;
        for (int i=0;i<prices.size()-1;i++){
            if (prices[i+1]-prices[i]>0)
                result+=prices[i+1]-prices[i];
        }
        
        return result;
    }
};
