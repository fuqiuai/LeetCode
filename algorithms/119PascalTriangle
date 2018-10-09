class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        // 使用滚动数组
        
        vector<int> result(rowIndex+1);
        
        if (rowIndex==0) return {1};
        
        for(int i=0;i<=rowIndex;i++){
            result[i]=1;
            for (int j = i - 1; j >= 1; j--){ 
                result[j] += result[j - 1];
            }
        }
        
        return result;
    }
};
