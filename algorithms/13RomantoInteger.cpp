class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        map<char,int> map1;
        map1['M']=1000;map1['D']=500;map1['C']=100;map1['L']=50;
        map1['X']=10;map1['V']=5;map1['I']=1;
        for (int i=0;i<s.size();i++){
            if (s[i]=='I'){
                if (s[i+1]=='V') {result+=4;i++;}
                else if (s[i+1]=='X') {result+=9;i++;}
                else result+=map1[s[i]];
            }
            else if (s[i]=='X'){
                if (s[i+1]=='L') {result+=40;i++;}
                else if (s[i+1]=='C') {result+=90;i++;}
                else result+=map1[s[i]];
            }
            else if (s[i]=='C'){
                if (s[i+1]=='D') {result+=400;i++;}
                else if (s[i+1]=='M') {result+=900;i++;}
                else result+=map1[s[i]];
            }
            else result+=map1[s[i]];
        }
        return result;
    }
};
