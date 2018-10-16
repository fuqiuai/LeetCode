class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c==0 || c==1 || c==2) return true;
        int a=0,b=sqrt(c);
        while(a<=b){
            if (a*a+b*b>c) b--;
            else if (a*a+b*b<c) a++;
            else return true;
        }
        return false;
    }

};
