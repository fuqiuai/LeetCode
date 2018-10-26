// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //找第一个使得isBadVersion为true的那个位置，简单的二分查找
        int l=1,r=n;
        while(l<r){
            int m=l/2+r/2; //不能写成(l+r)/2，因为后者在l+r较大时会溢出
            if (isBadVersion(m)) r=m;
            else l=m+1;
        }
        return l;
        
    }
};
