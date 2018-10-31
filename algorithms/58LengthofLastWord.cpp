class Solution {
public:
    int lengthOfLastWord(string s) {
        //从后往前找到第一个字母的位置
        int pos=-1;
        for (int i=s.size()-1;i>=0;i--)
            if (isalpha(s[i])){
                pos=i;break;
            }
        if (pos==-1) return 0; //不存在最后一个单词
        //寻找最后一个单词的起始位置
        int start;
        if (s.find_last_of(" ",pos)!=string::npos) start=s.find_last_of(" ",pos); 
        else start=-1;
        return pos-start;
    }
};
