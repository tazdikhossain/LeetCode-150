class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
      
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, 
                                             {0, -1},           {0, 1}, 
                                             {1, -1}, {1, 0}, {1, 1}};
        
        
        auto countLiveNeighbors = [&](int row, int col) {
            int liveCount = 0;
            for (auto [dr, dc] : directions) {
                int r = row + dr, c = col + dc;
                if (r >= 0 && r < m && c >= 0 && c < n && 
                    (board[r][c] == 1 || board[r][c] == 2)) {
                    liveCount++;
                }
            }
            return liveCount;
        };

        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = countLiveNeighbors(i, j);
                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[i][j] = 2; 
                }
                if (board[i][j] == 0 && liveNeighbors == 3) {
                    board[i][j] = -1; 
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) board[i][j] = 0;
                if (board[i][j] == -1) board[i][j] = 1;
            }
        }
    }
};
