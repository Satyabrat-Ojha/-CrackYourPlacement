class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int ans = m*n - walls.size() - guards.size();
        vector<vector<int>> grid(m, vector<int>(n,1));

        for(auto wall:walls) grid[wall[0]][wall[1]] = 2;
        for(auto guard:guards) grid[guard[0]][guard[1]] = 2;

        for(auto guard:guards) {
            int it = guard[0], jt = guard[1];
            grid[it][jt] = 0;

            for(int i=it;i<m;i++) {
                if(grid[i][jt] > 1) break;
                ans -= grid[i][jt];
                grid[i][jt] = 0;
            }
            for(int i=it;i>=0;i--) {
                if(grid[i][jt] > 1) break;
                ans -= grid[i][jt];
                grid[i][jt] = 0;
            }
            for(int j=jt;j<n;j++) {
                if(grid[it][j] > 1) break;
                ans -= grid[it][j];
                grid[it][j] = 0;
            }
            for(int j=jt;j>=0;j--) {
                if(grid[it][j] > 1) break;
                ans -= grid[it][j];
                grid[it][j] = 0;
            }

            grid[it][jt] = 2;
        }

        return ans;
    }
};