class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> N(n), M(m);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!matrix[i][j])
                    N[i]=M[j]=1;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(N[i] || M[j])
                    matrix[i][j]=0;
    }
};