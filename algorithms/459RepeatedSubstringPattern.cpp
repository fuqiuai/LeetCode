class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i=0;i<s.size();i++){
            string subStr=s.substr(0,i+1);
            if (repeatSubstr(s,subStr)) return true;
        }
        return false;
    }
private:
    bool repeatSubstr(string s,string sub){
        replace_all_distinct(s,sub,"#");
        if (s.size()==1) return false;
        for (int i=0;i<s.size();i++){
            if (s[i]!='#') return false;
        }
        return true;
    }
private: //用new_value替换字符串中所有的old_value
    string&   replace_all_distinct(string&   str, const  string&  old_value, const   string&   new_value)     
    {     
    for(string::size_type   pos(0);   pos!=string::npos;   pos+=new_value.length())  
    {     
        if(   (pos=str.find(old_value,pos)) != string::npos   )     
         { 
      str.replace(pos,old_value.length(),new_value);  
    }   
        else  { break; }    
    }     
    return   str;     
}
};
