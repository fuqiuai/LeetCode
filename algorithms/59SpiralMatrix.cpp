class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> result(n);
        for (int i=0;i<n;i++)
            result[i].resize(n);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                result[i][j]=0;
        
        int count=1,i=0,j=0;
        while(count<=n*n){
            while(j<n && !result[i][j]){  //向右
                result[i][j++]=count++;
            } 
            j--;i++;
            while(i<n && !result[i][j]){  //向下
                result[i++][j]=count++;
            } 
            i--;j--;
            while(j>=0 && !result[i][j]){  //向左
                result[i][j--]=count++;
            } 
            j++;i--;
            while(i>=0 && !result[i][j]){  //向上
                result[i--][j]=count++; 
            } 
            i++;j++;
        }
        
        return result;
    }
};
