class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0;i<m;i++) {
            if(matrix[i][0]) {
                for(int j=0;j<n;j++) {
                    matrix[i][j] ^= 1;
                }
            }
        }
        sort(matrix.begin(),matrix.end());
        int ans = 1, curr = 1;
        for(int i=1;i<m;i++) {
            if(matrix[i] == matrix[i-1]) curr++;
            else curr = 1;
            ans = max(ans,curr);
        }
        return ans;
    }
};