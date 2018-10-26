class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0;i<9;i++) //验证每一行
            if (!isRow(board,i))
                return false;
        for (int i=0;i<9;i++) //验证每一列
            if (!isColumn(board,i))
                return false;
        for (int i=0;i<9;i++) //验证每一个3x3宫
            if (!isPalace(board,i))
                return false;
        return true;
    }
private:
    bool isRow(vector<vector<char>> board, int row){
        vector<int> times(10,0);
        for (int i=0;i<9;i++)
            if (isdigit(board[row][i])) times[board[row][i]-'0']++;
        for (int i=0;i<10;i++)
            if (times[i]>=2) return false;
        return true;
    }
    bool isColumn(vector<vector<char>> board, int column){
        vector<int> times(10,0);
        for (int i=0;i<9;i++)
            if (isdigit(board[i][column])) times[board[i][column]-'0']++;
        for (int i=0;i<10;i++)
            if (times[i]>=2) return false;
        return true;
    }
    bool isPalace(vector<vector<char>> board, int k){
        vector<int> times(10,0);
        int startX,startY;
        if (k==0) {startX=0;startY=0;}
        if (k==1) {startX=0;startY=3;}
        if (k==2) {startX=0;startY=6;}
        if (k==3) {startX=3;startY=0;}
        if (k==4) {startX=3;startY=3;}
        if (k==5) {startX=3;startY=6;}
        if (k==6) {startX=6;startY=0;}
        if (k==7) {startX=6;startY=3;}
        if (k==8) {startX=6;startY=6;}
        for (int i=startX;i<startX+3;i++)
            for (int j=startY;j<startY+3;j++)
                if (isdigit(board[i][j])) times[board[i][j]-'0']++;
        for (int i=0;i<10;i++)
            if (times[i]>=2) return false;
        return true;
    }    
};
