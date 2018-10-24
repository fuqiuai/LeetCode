class Solution {
public:
    int hIndex(vector<int>& citations) {
        //基于274. H指数。这不过这里排序方式只能是从小到大（不然会超时），稍微变通即可
        if (citations.size()==0) return 0; 
        if (citations[citations.size()-1]==0) return 0;//所有的值都为0
        
        int n=citations.size();
        for (int i=0;i<n;i++)
            if (citations[i]>=n-i) //改了这里
                return n-i;
        return citations.size(); 
    }

};
