//迭代
class Solution {
public:
    string countAndSay(int n) {
        string str[31];
        str[1]="1";
        for (int i=2;i<=30;i++){
            string s=str[i-1];
            int begin=0,end=0;
            while(end<s.size()){
                if (end==s.size()-1 || s[end+1]!=s[end]){
                    str[i]+=(end-begin+1+'0');
                    str[i]+=s[begin];
                    begin=end+1;
                }
                end++;
            }
        }
        // for (int i=1;i<=30;i++)
        //     cout<<str[i]<<endl;
        return str[n];
    }
};
