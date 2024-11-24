class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int mn = 100000;
        bool neg_odd = 0;

        for(auto row:matrix) {
            for(auto num:row) {
                res += abs(num);
                mn = min(mn, abs(num));
                if(num < 0) neg_odd ^= 1;
            }
        }

        if(neg_odd) res -= mn + mn;
        return res;
    }
};