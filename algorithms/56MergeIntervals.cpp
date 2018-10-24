/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        //思路：按照start排序，然后往后合并（如果下一个合并不了，则下下个就更加合并不了了），合并不了则存入结果中
        if (intervals.size()<=1) return intervals;
        vector<Interval> res;
        sort(intervals.begin(),intervals.end(),cmp);
        // for (int i=0;i<intervals.size();i++)
        //     cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
        Interval temp=intervals[0];
        for (int i=1;i<intervals.size();i++){
            if (intervals[i].start<=temp.end){//合并
                temp.end=max(intervals[i].end,temp.end);
            }
            else{
                res.push_back(temp);
                temp=intervals[i];
            }
        }
        res.push_back(temp);
        return res;
    }
private:
    static bool cmp(Interval in1,Interval in2){
        return in1.start<in2.start;
    }
};
