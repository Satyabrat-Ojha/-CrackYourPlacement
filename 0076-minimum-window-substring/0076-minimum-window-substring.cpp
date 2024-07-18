class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> v(60);
        for(auto c:t) v[c - 'A']++;

        int l = t.size(), r = s.size(), idx = -1, sz;
        while(l <= r) {
            int m = (l + r) / 2;
            int w = window(m, s, v);
            if(w >= 0) {
                idx = w;
                sz = m;
                r = m - 1;
            }
            else l = m + 1;
        }

        return (idx == -1) ? "" : s.substr(idx, sz);
    }

    int window(int m, string s, vector<int>& v) {
        int n = s.size();
        vector<int> u(60);
        for(int i=0;i<n;i++) {
            u[s[i] - 'A'] ++;
            if(i - m >= 0) u[s[i - m] - 'A'] --;
            if(i - m + 1 >= 0 && check(u, v)) return i - m + 1; 
        }
        return -1;
    }

    bool check(vector<int>& u, vector<int>& v) {
        for(int i=0;i<60;i++)
            if(v[i] > u[i]) 
                return 0;
        return 1;
    }
};