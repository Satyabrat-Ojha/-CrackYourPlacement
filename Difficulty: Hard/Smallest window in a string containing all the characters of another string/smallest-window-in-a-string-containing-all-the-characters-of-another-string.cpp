//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        string ans = "-1";
        vector<int> v(26);
        for(auto c:p) v[c-'a']++;
        int l = p.size(), r = s.size();
        while(l <= r) {
            int mid = (l+r)/2;
            int x = window(mid, s, v);
            if(x >= 0) {
                ans = s.substr(x,mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
    
    int window(int n, string s, vector<int>& p) {
        vector<int> v(256);
        for(int i=0;i<s.size();i++) {
            v[s[i] - 'a']++;
            if(i-n >= 0) v[s[i-n] - 'a']--;
            if(i >= n-1 && cmp(v, p)) return i-n+1;
        }
        return -1;
    }
    
    bool cmp(vector<int>& v1, vector<int>& v2) {
        for(int i=0;i<26;i++) {
            if(v1[i] < v2[i]) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends