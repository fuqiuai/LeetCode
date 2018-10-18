class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos=0;
        for (int i=0;i<s.size();i++){
            bool flag=false;
            while(pos<t.size()){
                if (s[i]==t[pos]){
                    pos++;flag=true;
                    break;
                }
                pos++;
            }
            if (!flag) return false;
        }
        return true;
    }
};
