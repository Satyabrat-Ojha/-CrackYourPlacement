class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        for(int i=0;i<n/2;i++) {
            if(s[i] != s[n-1-i]) {
                return isPal(s.substr(i, n-i-i-1)) || isPal(s.substr(i+1, n-i-i-1));
            }
        }
        return true;
    }

    bool isPal(string s) {
        int n = s.size();
        for(int i=0;i<n/2;i++)
            if(s[i] != s[n-1-i]) return false;
        return true;
    }
};