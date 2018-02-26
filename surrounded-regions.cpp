class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty()) return;
        int rows = board.size();
        int cols = board[0].size();
        if (rows == 0 || cols == 0) return;
        // dfs上下边
        for (int i = 0;i < cols;i++) {
            if (board[0][i] == 'O') dfs(board, 0, i, 'O', '*');
            if (board[rows-1][i] == 'O') dfs(board, rows-1, i, 'O', '*');
        }
        
        // dfs左右边
        for (int j = 0;j < rows;j++) {
            if (board[j][0] == 'O') dfs(board, j, 0, 'O', '*');
            if (board[j][cols-1] == 'O') dfs(board, j, cols-1, 'O', '*');
        }
        
        // 将所有'O'变为'X'
        for (int m = 0;m < rows;m++) {
            for (int n = 0; n < cols;n++) {
                if (board[m][n] == 'O') board[m][n] = 'X';
                if (board[m][n] == '*') board[m][n] = 'O';
            }
        }
    }
    
    void dfs(vector<vector<char>> &board, int row, int col, char from, char to) {
        board[row][col] = to;
        if (col != board[0].size()-1 && board[row][col+1] == from)
            dfs(board, row, col+1, from, to);
        if (row != board.size()-1 && board[row+1][col] == from)
            dfs(board, row+1, col, from, to);
        if (col != 0 && board[row][col-1] == from)
            dfs(board, row, col-1, from, to);
        if (row != 0 && board[row-1][col] == from)
            dfs(board, row-1, col, from, to);
    }
};