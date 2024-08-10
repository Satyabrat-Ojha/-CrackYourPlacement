class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int t = 0, n = grid.size(), m = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()) {
            vector<int> top = pq.top();
            t = max(t, top[0]);
            grid[top[1]][top[2]] = -1;
            pq.pop();

            if(top[1] == n-1 && top[2] == m-1) break;

            vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
            for(auto d : directions) {
                int i = top[1] + d[0], j = top[2] + d[1];
                if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==-1) continue;
                pq.push({grid[i][j], i, j});
            }
        }

        return t;
    }
};