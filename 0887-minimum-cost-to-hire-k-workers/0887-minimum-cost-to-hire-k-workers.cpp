class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double ans;
        int n = wage.size(), sum = 0;
        vector<pair<int,double>> w;
        priority_queue<pair<double,int>> pq;
        
        for(int i=0;i<n;i++) w.push_back({quality[i], (double)wage[i] / quality[i]});
        sort(w.begin(),w.end());

        for(int i=0;i<k;i++) {
            sum += w[i].first;
            pq.push({w[i].second, i});
        }

        ans = sum * pq.top().first;

        for(int i=k;i<n;i++) {
            int idx = pq.top().second;
            pq.pop();

            sum += w[i].first - w[idx].first;

            pq.push({w[i].second, i});

            ans = min(ans, sum * pq.top().first);
        }

        return ans;
    }
};