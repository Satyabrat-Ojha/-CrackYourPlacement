class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> count(n), vis(n);
        for(auto edge:edges) {
            count[edge[0]]++;
            count[edge[1]]++;
        }

        vector<vector<int>> res;
        int corner = min_element(count.begin(), count.end()) - count.begin();
        vis[corner] = 1;
        
        if(check(count, 1)) res.push_back({corner});

        else if(!check(count, 4)) {
            res.push_back({corner});
            int x = -1;
            for(auto e:graph[corner]) {
                if(count[e] == 2) {
                    res.push_back({e});
                    vis[e] = 1;
                    break;
                }
            }
        }

        else {
            res.push_back({corner});
            do {
                for(auto e:graph[corner]) {
                    if(!vis[e] && count[e] < 4) {
                        res.push_back({e});
                        vis[e] = 1;
                        corner = e;
                        break;
                    }
                }
            } while(count[corner] != 2);
        }

        int rows = res.size();
        int cols = n / rows;

        for(int j=1;j<cols;j++) {
            for(int i=0;i<rows;i++) {
                int x = res[i].back();
                for(auto e:graph[x]) {
                    if(!vis[e]) {
                        res[i].push_back(e);
                        vis[e] = 1;
                        break;
                    }
                }
            }
        }

        return res;
    }

    bool check(vector<int>& count, int val) {
        for(auto c:count) if(c == val) return 1;
        return 0;
    }

};