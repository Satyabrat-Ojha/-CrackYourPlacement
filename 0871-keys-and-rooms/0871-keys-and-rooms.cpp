class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> dp(n);
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int room = q.front();
            q.pop();

            if(dp[room]) continue;
            dp[room] = 1;
            
            for(auto e:rooms[room]) {
                q.push(e);
            }
        }

        for(int i=0;i<n;i++) 
            if(!dp[i]) return 0;


        return 1;
    }
};