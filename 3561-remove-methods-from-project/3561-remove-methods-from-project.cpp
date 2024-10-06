class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> ans, vis(n);
        vector<vector<int>> graph(n);
        for(auto edge:invocations) {
            graph[edge[0]].push_back(edge[1]);
        }

        dfs(k, graph, vis);
        
        if(check(vis, invocations)) for(int i=0;i<n;i++) ans.push_back(i);
        else for(int i=0;i<n;i++) if(!vis[i]) ans.push_back(i);
        
        return ans;
    }

    void dfs(int k, vector<vector<int>>& graph, vector<int>& vis) {
        if(vis[k]) return;
        vis[k] = 1;
        for(auto e:graph[k]) dfs(e, graph, vis);
    }

    bool check(vector<int>& vis, vector<vector<int>>& invocations) {
        for(auto edge:invocations) if(vis[edge[1]] && !vis[edge[0]]) return 1;
        return 0;
    }
};