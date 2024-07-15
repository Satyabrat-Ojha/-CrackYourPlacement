class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = -1, x = 1, y = 0;
        vector<int> ans;

        while(n && m) {
            int t = (x==0) ? n : m;
            while(t--) {
                i += y; j += x;
                ans.push_back(matrix[i][j]);
            }

            if(x==0) {
                m--;
                x = -y;
                y = 0;
            }
            else {
                n--;
                y = x;
                x = 0;
            }
        }

        return ans;
    }
};