class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<pair<int,int>> st;
        st.push({0,-1});
        h.push_back(0);
        int ans = 0;
        for(int i=0;i<h.size();i++) {
            while (h[i] < st.top().first) {
                int x = st.top().first;
                st.pop();
                ans = max(ans, x * (i - 1 - st.top().second));
            } 
            st.push({h[i], i});
        }
        h.pop_back();
        return ans;
    }
};