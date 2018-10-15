class Solution {
public:
    string intToRoman(int num) {
        string result;
        while(num>=1000){result+='M';num-=1000;}
        while(num>=500){result+='D';num-=500;}
        while(num>=100){result+='C';num-=100;}
        while(num>=50){result+='L';num-=50;}
        while(num>=10){result+='X';num-=10;}
        while(num>=5){result+='V';num-=5;}
        while(num>=1){result+='I';num-=1;}
        replace_all_distinct(result,"DCCCC","CM"); //处理特殊情况
        replace_all_distinct(result,"CCCC","CD");
        replace_all_distinct(result,"LXXXX","XC");
        replace_all_distinct(result,"XXXX","XL");
        replace_all_distinct(result,"VIIII","IX");
        replace_all_distinct(result,"IIII","IV");
        
        return result;
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
