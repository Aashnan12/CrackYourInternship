class Solution {
public:
    int checkNeighbour(vector<vector<int>>& board, int i, int j, int m,
                        int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == 0)
            return 0;
        return 1;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> temp(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = checkNeighbour(board, i - 1, j - 1, m, n) +
                          checkNeighbour(board, i - 1, j, m, n) +
                          checkNeighbour(board, i - 1, j + 1, m, n) +
                          checkNeighbour(board, i, j - 1, m, n) +
                          checkNeighbour(board, i, j + 1, m, n) +
                          checkNeighbour(board, i + 1, j - 1, m, n) +
                          checkNeighbour(board, i + 1, j, m, n) +
                          checkNeighbour(board, i + 1, j + 1, m, n);
                cout<<cnt<<"  ";
                if(board[i][j] == 1){
                    if(cnt < 2 || cnt > 3){
                        temp[i][j] = 0;
                    }
                    else{
                        temp[i][j] = 1;
                    }
                }
                else{
                    if(cnt == 3){
                        temp[i][j] = 1;
                    }
                }
            }
        }

        board = temp;
        return;
    }
};