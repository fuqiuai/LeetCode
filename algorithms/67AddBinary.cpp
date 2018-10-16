class Solution {
public:
    string addBinary(string a, string b) {
        
        int len=max(a.size(),b.size());//补零
        if (a.size()<len){
            int temp=len-a.size();
            while(temp--){
                a+='0';
                for (int i=a.size()-1;i>=1;i--)
                    a[i]=a[i-1];
                a[0]='0';
            }
        }
        if (b.size()<len){
            int temp=len-b.size();
            while(temp--){
                b+='0';
                for (int i=b.size()-1;i>=1;i--)
                    b[i]=b[i-1];
                b[0]='0';
            }
        }
                
        int add=0;//进位
        string result(len,'0');
        for (int i=len-1;i>=0;i--){
            int temp=(a[i]-'0')+(b[i]-'0');
            result[i]=add+temp%2+'0';
            add=(result[i]-'0')/2+temp/2;
            result[i]=(result[i]-'0')%2+'0';
        }
        if (add==1){
            result+='0';
            for (int i=result.size()-1;i>=1;i--)
                    result[i]=result[i-1];
                result[0]='1';
        }
        return result;
    }
};
