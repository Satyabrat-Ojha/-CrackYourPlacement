class Solution {
    vector<vector<int>> dp;

public:
    int numDistinct(string s, string t) {
        dp.assign(1001, vector<int> (1001, -1));
        return count(s, t);
    }
    int count(string s, string t) {
        int i = s.size(), j = t.size();
        if(j == 0) return 1;
        if(i == 0 || i < j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = count(s.substr(1), t) + ((s[0] == t[0]) ? count(s.substr(1), t.substr(1)) : 0);
    }
};