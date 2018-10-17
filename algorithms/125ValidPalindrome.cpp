class Solution {
public:
    bool isPalindrome(string s) {
        //用双指针
        if (s.size()==0) return true;
	    transform(s.begin(),s.end(),s.begin(),::tolower);//将字符串转成小写
        int left=0,right=s.size()-1;
        while(left<right){
            if (!(isdigit(s[left]) || islower(s[left]))) left++;
            if (!(isdigit(s[right]) || islower(s[right]))) right--;
            if ((isdigit(s[left]) || islower(s[left])) && (isdigit(s[right]) || islower(s[right]))){
                if (s[left]!=s[right])
                    return false;
                else{
                    left++;right--;
                }
            }
        }
        
        return true;
    }
};
