class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //首先用循环截取s2中与s1等长的子串，再将每个子串与s1比较是否是排列
        if (s1.size()>s2.size()) return false;
        if (s1.size()==0) return true;
        else if (s2.size()==0) return false;
        
        for (int i=0;i<=s2.size()-s1.size();i++){
            string sub=s2.substr(i,s1.size());
            if (checkSam(s1,sub)) 
                return true;
        }
        return false;
    }
    
private://判断一个字符串是否是另一个字符串的排列
    bool checkSam(string sa,string sb){
        vector<int> numa(125,0);
        vector<int> numb(125,0);
        for (int i=0;i<sa.size();i++){
            numa[sa[i]]++;
            numb[sb[i]]++;
        }
        for (int i=0;i<125;i++){
            if (numa[i]!=numb[i])
                return false;
        }
        return true;
        
    }
};
