class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& pts, int k) {
        priority_queue<pair<int, int>> pq;
        int ans= INT_MIN;
        for(int i=0;i<pts.size();i++) {
            while(!pq.empty() && pts[i][0] - pq.top().second > k) pq.pop();
            if(!pq.empty()) ans = max(ans, pts[i][0] + pts[i][1] + pq.top().first);
            pq.push({pts[i][1] - pts[i][0], pts[i][0]});
        }
        return ans;
    }
};