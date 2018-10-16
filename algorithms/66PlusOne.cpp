class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        digits[digits.size()-1]++;
        int add=digits[digits.size()-1]/10;
        digits[digits.size()-1]%=10;

        for (int i=digits.size()-2;i>=0;i--){
            digits[i]+=add;
            add=digits[i]/10;
            digits[i]%=10;
        }
        if (add==0) return digits;
        else{
            vector<int> result(digits.size()+1);
            result[0]=add;
            for (int i=1;i<result.size();i++)
                result[i]=digits[i-1];
            return result;
        }
    }
};
