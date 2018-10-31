class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        for (int i=1;i<=n;i++)
            str+=(char)(i+'0');
        int i=1;
        do  
        {  
            if (i==k) return str;
            i++;
        }while(next_permutation(str.begin(),str.end())); 
    }
};
