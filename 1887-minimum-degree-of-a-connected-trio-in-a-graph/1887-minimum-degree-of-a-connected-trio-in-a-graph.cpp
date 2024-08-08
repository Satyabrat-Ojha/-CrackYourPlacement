class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n);
        for(auto e:edges) {
            int u = e[0], v = e[1];
            u--;
            v--;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        
        int ans = INT_MAX;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    if(adj[i].find(j) == adj[i].end()) continue;
                    if(adj[j].find(k) == adj[j].end()) continue;
                    if(adj[i].find(k) == adj[i].end()) continue;

                    int sum = -6;
                    sum += adj[i].size();
                    sum += adj[j].size();
                    sum += adj[k].size();
                    ans = min(ans, sum);
                }
            }
        }

        if(ans == INT_MAX) return -1;

        return ans;
    }
};