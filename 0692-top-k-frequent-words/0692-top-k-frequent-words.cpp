class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        sort(words.begin(),words.end());
        vector<pair<int,string>> v;
        for(auto s:words) {
            if(v.empty() || s != v.back().second) v.push_back({0,s});
            else v.back().first--;
        }
        sort(v.begin(),v.end());
        vector<string>ans;
        for(int i=0;i<k;i++) ans.push_back(v[i].second);
        return ans;
    }
};