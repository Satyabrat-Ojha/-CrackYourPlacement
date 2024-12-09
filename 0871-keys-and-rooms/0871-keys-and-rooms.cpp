class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> dp(n);
        queue<int> q;
        q.push(0);
        do {
            int room = q.front();
            q.pop();

            if(dp[room]) continue;
            dp[room] = 1;
            
            for(auto e:rooms[room]) {
                q.push(e);
            }
        } while(!q.empty());

        int i=0;
        do {
            if(!dp[i]) return 0;
            i++;
        } while (i < n);

        return 1;
    }
};