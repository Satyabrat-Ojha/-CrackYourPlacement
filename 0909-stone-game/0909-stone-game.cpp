class Solution {
    int dp[501][501] = {0};
public:
    bool stoneGame(vector<int>& piles) {
        return alice(0, piles.size()-1, piles) > 0;
    }

    int alice(int st, int en, vector<int>& p) {
        if(st == en) return p[st];
        if(dp[st][en] != 0) return dp[st][en];
        return dp[st][en] = max(p[st] - alice(st+1,en,p), p[en] - alice(st,en-1,p));
    }
};