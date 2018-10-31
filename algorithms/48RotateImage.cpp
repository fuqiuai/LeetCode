//方案1：假设旋转后的矩阵为m2,原矩阵为m1,则m2与m1之间的关系为m2[i][j]=m1[n-1-j,i]、
//由于此题为原地旋转，因此方案1不可行，方案2：将原矩阵（左上至右下）斜对称交换，再竖对称交换即可
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if (n<=1) return;
        for (int i=0;i<n;i++) //斜对称交换
            for (int j=i+1;j<n;j++)
                swap(matrix[i][j],matrix[j][i]);
        for (int i=0;i<n;i++) //竖对称交换
            for (int j=0;j<n/2;j++)
                swap(matrix[i][j],matrix[i][n-1-j]);                  

    }
};
