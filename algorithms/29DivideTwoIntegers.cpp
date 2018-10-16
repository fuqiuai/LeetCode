class Solution {
public:
    int divide(int dividend, int divisor) {
        //用循环+加减法操作

        long long d1=abs((long long)dividend),d2=abs((long long)divisor); //注意abs要用long long转换
        long long sum=d2,result=0;
        // while(sum<=d1){ //方法1：会超时
        //     result++;
        //     sum+=d2;
        // }
        while(d2<=d1){ //方法2：复杂度优化为logN
            sum=d2;
            long long count=1;
            while(sum+sum<=d1){
                count+=count;
                sum+=sum;
            }
            d1-=sum;
            result+=count;
        }
        if ((dividend>0 && divisor<0) || (dividend<0 && divisor>0)) return 0-result;
        else{
            if (result>=INT_MAX) return INT_MAX;
            else return result;
        }
    }
};
