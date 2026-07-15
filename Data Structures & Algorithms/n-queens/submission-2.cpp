class Solution {
public:
    void backtrack(int row, int n, vector<vector<string>>& ans, vector<string> &board, vector<bool> &cols, vector<bool> &posd, vector<bool> &negd) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int pdiag = row + col;
            int ndiag = row - col + n;
            if (cols[col] || posd[pdiag] || negd[ndiag]) continue;

            board[row][col] = 'Q';
            cols[col] = true;
            posd[pdiag] = true;
            negd[ndiag] = true;

            backtrack(row + 1, n, ans, board, cols, posd, negd);

            board[row][col] = '.';
            cols[col] = false;
            posd[pdiag] = false;
            negd[ndiag] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> posd(2 * n - 1, false);
        vector<bool> negd(2 * n - 1, false);
        vector<vector<string>> ans;
        backtrack(0, n, ans, board, cols, posd, negd);
        return ans;
    }
};
