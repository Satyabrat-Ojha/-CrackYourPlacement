class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        
        for(auto &v:box) {
            stack<bool> obj;
            for(int i=0;i<n;i++) {
                if(v[i] == '*') obj.push(0);
                if(v[i] == '#') obj.push(1);
            }

            for(int i=n-1;i>=0;i--) {
                if(v[i] == '*') obj.pop();
                else if(!obj.empty() && obj.top()) {v[i] = '#'; obj.pop();}
                else v[i] = '.'; 
            }
        }

        vector<vector<char>> ans(n, vector<char>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans[i][j] = box[m-1-j][i];
            }
        }
        return ans;
    }
};