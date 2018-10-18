class Solution {
public:
    string removeKdigits(string num, int k) {
        //贪心算法。贪心策略：每次从第0个元素起，移走第一个递减序对[pos,pos+1](num[pos]>num[pos+1])中的pos这个元素
        if (k==0) return num; 
        if (num.size()==k) return "0";
        while(k--){
            bool flag=false;
            for (int i=0;i<num.size();i++){ //找到第一个递减序对
                if (num[i]>num[i+1]){
                    num.erase(i,1);
                    flag=true;
                    break;
                }
            }
            if (!flag) num.erase(num.size()-1,1);//没有递减序对时，删除最后一个元素
        }
        //处理前导零
        int len=0;bool fa=false;
        for (int i=0;i<num.size();i++){
            if (num[i]!='0'){
                len=i;
                fa=true;
                break;
            }
        }
        if (!fa) return "0";//结果全为0，则输出一个0就好
        num.erase(0,len);
        return num;
    }
};
