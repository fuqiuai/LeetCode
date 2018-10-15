class Solution {
public:
    string convert(string s, int numRows) {        
        /*规律：第一行和最后一行的字母下标数是一个等差数列，差值为d=2*numRows-2
        其他行的把满列的和单列的数字分成两部分来看，满列的依然是差值为d的等差数列，单列的值为pos+d-2*i（pos是前面一个整列数字的位置，i是行数）*/
        
        if (numRows<=1) return s; //特殊情况

        string result;
        int d=2*numRows-2;
        for (int i=0;i<numRows;i++){ //从第一行遍历到最后一行
            for (int pos=i;pos<s.size();pos+=d){
                //第一行、最后一行数字和其他行的整列数字
                result+=s[pos];
                
                //其他行的单列数字
                int tmp=pos+d-2*i; 
                if (i!=0 && i!=numRows-1 && tmp<s.size())
                    result+=s[tmp];
            }   
        }
        
        return result;
    }
};
