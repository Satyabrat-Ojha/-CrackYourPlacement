class Solution {
public:
    string reverseWords(string s) {
        removeSpaces(s);
        reverse(s.begin(),s.end());
        int n = s.size(), idx = 0;
        for(int i=0;i<n;i++) {
            if(i == n-1 || s[i+1] == ' ') {
                reverse(s.begin() + idx, s.begin() + i + 1);
                idx = i+2;
            }
        }
        return s;
    }

    void removeSpaces(string& s) {
        int idx = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i] == ' ' && (i == 0 || s[i-1] == ' ')) continue;
            s[idx] = s[i];
            idx++;
        }
        while(s.size() > idx || s.back() == ' ') s.pop_back();
    }
};