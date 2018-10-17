class Solution {
public:
    string reverseVowels(string s) {
        int left=0,right=s.size()-1;
        map<char,int> map1;
        map1['a']=1;map1['e']=1;map1['i']=1;map1['o']=1;map1['u']=1;
        map1['A']=1;map1['E']=1;map1['I']=1;map1['O']=1;map1['U']=1;
        while(left<right){
            while (!map1[s[left]]) left++;
            while (!map1[s[right]]) right--;  
            if (left<right) swap(s[left],s[right]);
            left++;right--;
        }
        return s;
    }
};
