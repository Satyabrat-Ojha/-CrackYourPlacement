class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return 0;

        int dp1[26] = {0}, dp2[26] = {0};
        for(auto c:s1) {
            dp1[c-'a']++;
        }
        
        int n1 = s1.size(), n2 = s2.size();

        for(int i=0;i<n1;i++) {
            dp2[s2[i] - 'a']++;
        }

        if(check(dp1,dp2)) return 1;

        for(int i=n1;i<n2;i++) {
            dp2[s2[i]-'a']++;
            dp2[s2[i-n1]-'a']--;
            if(check(dp1,dp2)) return 1;
        }

        return 0;
    }

    bool check(int dp1[], int dp2[]) {
        for(int i=0;i<26;i++) {
            if(dp1[i] > dp2[i]) return 0;
        }

        return 1;
    }
};