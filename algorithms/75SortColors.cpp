class Solution {
public:
    void sortColors(vector<int>& nums) {
        //计数排序
        vector<int> jishu(3,0);
        for (int i=0;i<nums.size();i++)
            jishu[nums[i]]++;
        cout<<jishu[0]<<" "<<jishu[1]<<" "<<jishu[2];
        for (int i=0;i<jishu[0];i++)
            nums[i]=0;
        for (int i=jishu[0];i<jishu[1]+jishu[0];i++)
            nums[i]=1;
        for (int i=jishu[1]+jishu[0];i<jishu[2]+jishu[1]+jishu[0];i++)
            nums[i]=2;
    }
};
