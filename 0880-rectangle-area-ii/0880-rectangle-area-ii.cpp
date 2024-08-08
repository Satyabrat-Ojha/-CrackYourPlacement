class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int> x;
        for(auto r:rectangles) {
            x.insert(r[0]);
            x.insert(r[2]);
        }
        vector<int> xc;
        for(auto e:x) xc.push_back(e);

        vector<vector<vector<int>>> range(xc.size()-1);
        for(int i=0;i<range.size();i++) {
            int t = xc[i];
            for(auto r:rectangles) {
                if(r[0] <= t && r[2] > t) {
                    range[i].push_back({r[1], r[3]});
                }
            }
        }

        for(auto &r:range)
            sort(r.begin(), r.end());

        long long N = 1e9+7, ans = 0;

        for(int i=0;i<range.size();i++) {
            long long w = xc[i+1] - xc[i];
            long long l = helper(range[i]);

            ans = (ans + l*w) % N;
        }

        return ans;
    }

    long long helper(vector<vector<int>>& v) {
        if(v.empty()) return 0;
        vector<vector<int>> t = merge(v);

        long long ans = 0;
        for(auto e:t) {
            ans += e[1] - e[0];
        }

        return ans;
    }

    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
	    ans.push_back(arr[0]);
	    for(auto a:arr) {
		    if(a[0]<=ans[ans.size()-1][1])
			    ans[ans.size()-1][1] = max(a[1],ans[ans.size()-1][1]);
		    else
			    ans.push_back(a);
	    }
	    return ans;
    }
};