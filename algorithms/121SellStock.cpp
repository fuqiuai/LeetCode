// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         //方法1：暴力法
//         if (prices.size()<=1) return 0;
//         int result=0;
//         for (int i=0;i<prices.size();i++){
//             for (int j=i+1;j<prices.size();j++){
//                     result=max(result,prices[j]-prices[i]);
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //方法2：保存一个买入价格
        if (prices.size()<=1) return 0;
        int result=INT_MIN,buyPrice=INT_MAX;
        for (int i=0;i<prices.size();i++){
            buyPrice=min(buyPrice,prices[i]);//买入时价格
            result=max(result,prices[i]-buyPrice);//最大利润
        }
        return result;
    }
};
