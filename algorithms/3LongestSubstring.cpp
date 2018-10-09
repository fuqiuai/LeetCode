// # 方法1：暴力法，时间复杂度O(n^3)
// class Solution {
// public:
//     bool hasRepeatWord(string str,char ch){
//         for (int i=0;i<str.size();i++){
//             if (ch == str[i])
//                 return true;
//         }    
//         return false;
//     }
    
//     int lengthOfLongestSubstring(string s) {
//         if (s=="")
//             return 0;
//         int maxLen=1;
//         for (int i=0;i<s.size();i++){
//             for (int j=i+1;j<s.size();j++){
//                 if (hasRepeatWord(s.substr(i,j-i),s[j]))
//                     break;
//                 if (j-i+1>maxLen)
//                     maxLen=j-i+1;
//             }
//         }
//         return maxLen;
//     }
// };

// 方法2：动态规划,时间复杂度O(n)
// 如果s[j]在[i, j)范围内有与j′重复的字符，我们不需要逐渐增加i。我们可以直接跳过[i，j′]范围内的所有元素，并将i变为j′+1。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(256, -1);  //将向量中的元素都初始化为-1
        int maxLen = 0;  
        
        for (int j = 0, i = 0; j < s.size(); j++) {
            i = max(pos[s[j]], i);
            maxLen = max(maxLen, j - i + 1);
            pos[s[j]] = j + 1;
        }
        return maxLen;  
    }
};
