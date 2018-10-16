class Solution {
public:
    double myPow(double x, int n) {
        //利用递归
        if(n<0)
            return 1/power(x,-n);
        else
            return power(x,n);
    }
private:
    double power(double x, int n){
        if (n==0) return 1;
        else if (n%2==0) return power(x,n/2)*power(x,n/2);
        else return power(x,n/2)*power(x,n/2)*x;
        
    }
};
