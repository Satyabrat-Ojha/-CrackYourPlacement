class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int ans = m*n - walls.size() - guards.size();
        vector<vector<int>> grid(m, vector<int>(n,1));

        for(auto wall:walls) grid[wall[0]][wall[1]] = 2;
        for(auto guard:guards) grid[guard[0]][guard[1]] = 2;

        for(auto guard:guards) {
            int it = guard[0], jt = guard[1];
            vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

            for(auto [x,y] : directions) {
                int i = it+x, j = jt+y;
                while(i>=0 && i<m && j>=0 && j<n && grid[i][j]!=2) {
                    ans -= grid[i][j];
                    grid[i][j] = 0;
                    i += x;
                    j += y;
                }
            }
        }

        return ans;
    }
};