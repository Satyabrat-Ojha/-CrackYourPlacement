class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;
        int n = grid.size(), m = grid[0].size(), it = 2;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j] == 1)
                    dfs(it++, i,j,grid,mp);

        int ans = 0;
        for(auto e:mp) ans = max(ans, e.second);

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 0) {
                    int sum = calc(i,j,grid,mp);
                    ans = max(ans, sum);
                }
            }
        }

        return ans;
    }

    void dfs(int val, int i, int j, vector<vector<int>>& grid, unordered_map<int,int>& mp) {
        if(i<0 || j<0 || i>=grid.size() ||j>=grid[0].size()) return;
        if(grid[i][j] != 1) return;
        grid[i][j] = val;
        mp[val]++;

        dfs(val,i+1,j,grid,mp);
        dfs(val,i,j+1,grid,mp);
        dfs(val,i-1,j,grid,mp);
        dfs(val,i,j-1,grid,mp);
    }

    int calc(int i, int j, vector<vector<int>>& grid, unordered_map<int,int>& mp) {
        set<int> s;
        s.insert(search(i+1,j,grid));
        s.insert(search(i,j+1,grid));
        s.insert(search(i-1,j,grid));
        s.insert(search(i,j-1,grid));
        
        int sum = 0;
        for(auto e:s) sum += mp[e];
        return sum+1;
    }

    int search(int i, int j, vector<vector<int>>& grid) {
        if(i<0 || j<0 || i>=grid.size() ||j>=grid[0].size()) return 0;
        return grid[i][j];
    }
};