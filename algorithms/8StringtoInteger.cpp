class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0; //特殊情况1：字符串为空
        int pos=-1;//找到第一个非空字符
        for (int i=0;i<str.size();i++){
            if (!isspace(str[i]))
            {
                pos=i;
                break;
            }
        }
        if (pos==-1) return 0; //特殊情况2：字符串仅包含空白字符
        int sign=1; //1正 -1负
        if (str[pos]=='-') {sign=-1;pos++;}
        else if (str[pos]=='+') {sign=1;pos++;}
        if (!isdigit(str[pos])) return 0; //特殊情况3：第一个非空字符不是数字
        
        //通过找到第二个不为数字的位置，选取连续的数字组合
        int pos2=str.size();
        for (int i=pos+1;i<str.size();i++){
            if (!isdigit(str[i])){
                pos2=i;
                break;
            }
        }
        string subNum=str.substr(pos,pos2-pos);
        long long result=0; 
        for (int i=0;i<subNum.size();i++){
            result*=10;
            result+=(subNum[i]-'0');
            if (sign==1 && result>=INT_MAX) return INT_MAX;
            if (sign==-1 && result>INT_MAX) return INT_MIN;
        }
        return result*sign;

    }
    
};
