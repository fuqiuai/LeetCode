class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string S=A;
        int k=1;
        while(S.size()<=10000){
            if (S.find(B)!=-1) return k;
            else{
                S+=A;k++;
            }
        }
        return -1;
    }
};
