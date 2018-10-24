class Solution {
public:
    int hIndex(vector<int>& citations) {
        //有N篇论文分别被引用了至少N次，他的H指数就是N，求H指数步骤如下：
        //(1)将其发表的所有SCI论文按被引次数从高到低排序；
        //(2)从前往后查找排序后的列表，直到某篇论文的序号(从1开始)大于该论文被引次数。所得序号减一即为H指数。
        if (citations.size()==0) return 0; 
        
        sort(citations.begin(),citations.end(),cmp);
        for (int i=0;i<citations.size();i++)
            if (citations[i]<i+1)
                return i;
        return citations.size(); //如果所有的序号都不大于被引次数，则论文数就是H指数，如[11,15]结果为2
    }
private:
    static bool cmp(int a,int b){
        return a>b;
    }
};
