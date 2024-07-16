class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>> v;
        for(auto str : strs) v.push_back({str, str});
        for(auto &[x,y] : v) sort(x.begin(),x.end());
        sort(v.begin(),v.end());
       
        vector<vector<string>> ans;
        ans.push_back({v[0].second});
        for(int i=1;i<v.size();i++) {
            if(v[i].first != v[i-1].first) ans.push_back({v[i].second});
            else ans.back().push_back(v[i].second);
        }
        return ans;
    }
};