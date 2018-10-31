class Solution {
public:
    void reverseWords(string &s) {
        //去掉首尾空格
        int k=-1;
        for (int i=0;i<s.size();i++)
            if (s[i]!=' '){k=i;break;}
        if (k==-1) {s="";return;}  //特殊情况：全都是空格
        s.erase(0,k);
        for (int i=s.size()-1;i>=0;i--)
            if (s[i]!=' '){k=i;break;}
        s.erase(k+1,s.size()-1-k);
        //开始翻转
        reverse(s.begin(),s.end());
        int begin=0;
        while(begin<s.size()){
            int end; //end指向单词后的第一个空格
            if (s.find(" ",begin)==string::npos) end=s.size();
            else end=s.find(" ",begin);
            reverse(s.begin()+begin,s.begin()+end); //翻转单词
            if (end==s.size()) break;
            for (int i=end;i<s.size();i++)  //begin指向下一个单词的第一个字母
                if (s[i]!=' '){begin=i;break;}
            s.erase(end,begin-end-1);//去除多余的空格
            begin-=(begin-end-1);
        }        
    }
};
