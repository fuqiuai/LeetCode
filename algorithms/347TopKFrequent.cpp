class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){ //降序排序
        return a.second>b.second;
    }  
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //使用map统计每个数字出现的频率，然后将map元素存入vector中，再对vector排序
        map<int,int> m;
        for (int i=0;i<nums.size();i++)
            m[nums[i]]++;

        vector<pair<int,int>> vec(m.begin(),m.end());
        sort(vec.begin(), vec.end(), cmp);    
        
        vector<int> res;
        for (int i=0;i<k;i++)
            res.push_back(vec[i].first);
        return res;     
    }

};
