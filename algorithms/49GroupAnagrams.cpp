//解题思路：对字符串的每个词对字母按照字典序进行排序，那么所有的异位词对字母进行排序后应当有相同的字母序列，以该字母序列作为映射的key，将所有异位词都保存到字符串数组中，建立key和字符串数组之间的映射，最后再存入结果res中即可。
//*map和unordered_map的区别: 如果需要内部元素自动排序，使用map，不需要排序使用unordered_map
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.size()==0) return res;
        unordered_map<string,vector<string>> map1;
        for (int i=0;i<strs.size();i++){ //建立key与字符串数组之间的映射
            string s=strs[i];
            sort(s.begin(),s.end());
            map1[s].push_back(strs[i]);
        }
        for (auto v:map1) //遍历unordered_map
            res.push_back(v.second);
        return res;
    }
    
};
