class Solution {
public:
    bool validPalindrome(string s) {
/*思路：双指针思想。以下两种情况使字符串能够成为回文串
    (1) i,j移动过程中（i<j），i指向的字符始终与j指向的字符相同。
    (2) i,j移动过程中（i<j），i++之后i指向的字符始终与j指向的字符相同，或者i指向的字符始终与j--之后j指向的字符相同，只要条件满足其一即可。
*/
        
        if (s.size()<=2) return true;
        
        int left=0,right=s.size()-1;
        while(left<right){
            if (s[left]!=s[right]){
                if (isPalindrome(s,left+1,right) || isPalindrome(s,left,right-1))
                    return true;
                else 
                    return false;
            }
            left++;right--;
        }        
        return true;
        
    }
    
public: //判断是否为回文串
    bool isPalindrome(string s,int left,int right) {
        while(left<right){
            if (s[left]!=s[right]) return false;
            left++;right--;
        }        
        return true;
    }
};
