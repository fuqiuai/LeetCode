class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;

        int m=matrix.size(),n=matrix[0].size();
        
        vector<vector<bool>> flag(m); //标记某个位置上的值是否被读取
        for (int i=0;i<m;i++)
            flag[i].resize(n);
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                flag[i][j]=true;

        
        int count=0;
        int i=0,j=0;
        while(count<m*n){
            while(j<n && flag[i][j]){  //向右
                flag[i][j]=false; result.push_back(matrix[i][j++]); count++; 
            } 
            j--;i++;
            while(i<m && flag[i][j]){  //向下
                flag[i][j]=false; result.push_back(matrix[i++][j]); count++; 
            } 
            i--;j--;
            while(j>=0 && flag[i][j]){  //向左
                flag[i][j]=false; result.push_back(matrix[i][j--]); count++; 
            } 
            j++;i--;
            while(i>=0 && flag[i][j]){  //向上
                flag[i][j]=false; result.push_back(matrix[i--][j]); count++;  
            } 
            i++;j++;
        }
        
        return result;
        
    }
};
