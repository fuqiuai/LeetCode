class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1=="0" || num2=="0") return "0";
        
        vector<int> vec(13000,0);  //模拟乘法
        for (int i=num1.size()-1;i>=0;i--){
            int add=0;//进位
            for (int j=num2.size()-1;j>=0;j--){
                int temp=(num1[i]-'0')*(num2[j]-'0');
                vec[i+j+1]+=add+temp%10;
                add=temp/10+vec[i+j+1]/10;
                vec[i+j+1]%=10;
            }
            vec[i]=add;
        }
        
        string result=""; //将vector中存储的结果转化成string
        int pos=0;
        for (int i=0;i<num1.size()+num2.size();i++){
            if (vec[i]!=0){
                pos=i;
                break;
            }
        }

        for (int i=pos;i<num1.size()+num2.size();i++)
            result+=vec[i]+'0';        
        return result;
    }
};
