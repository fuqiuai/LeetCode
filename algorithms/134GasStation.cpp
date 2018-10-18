// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         //方法1：遍历一遍数组，将每个加油站设为出发站，依次判断；
//         int n=gas.size();
//         for (int i=0;i<n;i++){
//             vector<int> gasNew(n),costNew(n);
//             for (int j=0;j<n;j++){
//                 gasNew[j]=gas[(j+i)%n];
//                 costNew[j]=cost[(j+i)%n];
//             }
//             if (isComplete(gasNew,costNew)) return i;
//         }
//         return -1;
//     }
    
// private:
//     bool isComplete(vector<int> gas, vector<int> cost){
//         int n=gas.size();
//         int gasRest=gas[0];
//         for (int i=1;i<n;i++){
//             if (gasRest<cost[i-1]) return false;
//             gasRest=gasRest-cost[i-1]+gas[i];
//         }
//         if (gasRest<cost[n-1]) return false;
//         return true;
//     }
// };

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //方法2：
        int n=gas.size();
        int gasRest=0,sum=0,start=0;
        for (int i=0;i<n;i++){
            gasRest+=gas[i]-cost[i];
            sum+=gas[i]-cost[i];
            if (sum<0){
                start=i+1;
                sum=0;
            }
        }
        return (gasRest<0)?-1:start;
    }
};
