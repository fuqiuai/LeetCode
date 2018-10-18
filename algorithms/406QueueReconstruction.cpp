class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        //思路：首先找到最矮的人，他放置的位置就是他的k值，
        //再找到第二矮的人（如果身高相同，则找k值较大的那个），他放置的位置应该是前面有k个未放置的位置时的那个位置，然后依次类推
        int n=people.size();
        vector<pair<int, int>> result(n);
        
        bool flag[1101]={false};
        
        while(n--){
            //依次找到队列中最矮的人，第二矮的人，...
            pair<int,int> min(INT_MAX,0);
            int minPos=0;
            for (int i=0;i<people.size();i++){ 
                if (people[i].first<min.first || (people[i].first==min.first && people[i].second>min.second)){ //要注意处理身高相同的情况，身高相同则优先选取k值较大的那个
                    min=people[i];
                    minPos=i;
                }
            }
            //放置到新队列
            int falseNum=0;
            for (int i=0;i<result.size();i++){
                if (!flag[i]) falseNum++;
                if (falseNum==people[minPos].second+1){
                    result[i]=people[minPos];  
                    flag[i]=true;
                    break;
                }
            }        
            people.erase(people.begin()+minPos);
        }
        
        return result;
                
    }
};
