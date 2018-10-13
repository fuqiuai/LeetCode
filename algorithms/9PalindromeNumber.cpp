class Solution {
public:
    bool isPalindrome(int x) {
        // if (x<0) return false;
        string str=to_string(x);
        string str2=str;
        reverse(str.begin(),str.end());
        if (str2==str) return true;
        else return false;
    }
};
