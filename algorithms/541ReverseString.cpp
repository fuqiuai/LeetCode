class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.size()<=1 || k<=1) return s; //特殊情况
        int left=0;
        int len=s.size();
        while(left<=len-2*k){
            reverse(s.begin()+left,s.begin()+left+k);
            left+=2*k;
        }
        int res=s.size()-left;//剩下的字符数
        if (res<=k) reverse(s.begin()+left,s.end()); //情况1：剩余少于 k 个字符
        else reverse(s.begin()+left,s.begin()+left+k); //情况2：剩余小于 2k 但大于或等于 k 个字符
        
        return s;
    }
};
