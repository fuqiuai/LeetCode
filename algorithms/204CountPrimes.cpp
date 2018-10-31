class Solution {
public:
    int countPrimes(int n) {
        //筛法求素数
        vector<int> prime(n,1);
        for (int i=2;i<n;i++)
            for (int j=2*i;j<n;j+=i)
                prime[j]=0;
        
        int res=0;
        for (int i=2;i<n;i++)
            if (prime[i])
                res++;
        return res;
    }
};
