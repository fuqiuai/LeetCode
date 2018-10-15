class Solution {
public:
    bool checkRecord(string s) {
        if (s.find("LLL")!=-1) return false;
        int numA=0;
        for (int i=0;i<s.size();i++)
            if (s[i]=='A')
                numA++;
        if (numA>1) return false;
        return true;
        
    }
};
