class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int c = count(i,j,board);
                if(board[i][j] && c < 2) v.push_back({i,j});
                else if(board[i][j] && c > 3) v.push_back({i,j});
                else if(!board[i][j] && c == 3) v.push_back({i,j}); 
            }
        }

        for(auto [i,j]:v) {
            board[i][j] ^= 1;
        }
    }

    int count(int i, int j, vector<vector<int>>& board) {
        int c = 0, n = board.size(), m = board[0].size();
        if(i>0 && board[i-1][j]) c++;
        if(j>0 && board[i][j-1]) c++;
        if(i<n-1 && board[i+1][j]) c++;
        if(j<m-1 && board[i][j+1]) c++;
        if(i>0 && j>0 && board[i-1][j-1]) c++;
        if(i>0 && j<m-1 && board[i-1][j+1]) c++;
        if(i<n-1 && j>0 && board[i+1][j-1]) c++;
        if(i<n-1 && j<m-1 && board[i+1][j+1]) c++;
        return c;
    }
};