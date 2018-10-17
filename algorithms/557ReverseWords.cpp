class Solution {
public:
    string reverseWords(string s) {
        if (s.size()<=1) return s;
        
        int left=0,right=0;
        while(right<s.size()){
            int i=left;
            for (;i<s.size();i++){//找到空格
                if (isspace(s[i])){
                    right=i;
                    break;
                }
            }
            if (i==s.size()) right=s.size();
            reverse(s.begin()+left,s.begin()+right);
            left=right+1;
        }
        return s;

    }
};
