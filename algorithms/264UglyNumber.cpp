// 首先定义一个数组存放丑数，认为1是丑数，则初始化数组ugly[0] = 1，然后从2,3,5这三个种子中挑选，选择ugly[0]*2，ugly[0]*3，ugly[0]*5中最小的数为新的丑数，显然应该选择2，即ugly[1] = 2，然后在从2,3,5中选择，这时应该是从ugly[1]*2，ugly[0]*3，ugly[0]*5中进行选择，显然选择3，即ugly[2] = 3，然后再从ugly[1]*2，ugly[1]*3，ugly[0]*5中选择最小的，选择2，即ugly[3] = 4，依次进行如下操作，得到最终的结果。

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0]=1;
        int num2=0,num3=0,num5=0;
        for (int i=1;i<n;i++){
            ugly[i]=min(min(ugly[num2]*2,ugly[num3]*3),ugly[num5]*5);
            if (ugly[num2]*2==ugly[i]) num2++;
            if (ugly[num3]*3==ugly[i]) num3++;
            if (ugly[num5]*5==ugly[i]) num5++;
        }
        return ugly[n-1];
    }

};
