class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int> pmx;
        priority_queue<int, vector<int>, greater<int>> pmn;
        for(auto num:nums) {
            pmx.push(num);
            pmn.push(num);
            if(pmx.size() > 2) pmx.pop();
            if(pmn.size() > 3) pmn.pop();
        }
        int a = 1, b = 1;
        a *= pmx.top(); pmx.pop();
        a *= pmx.top(); pmx.pop();
        b *= pmn.top(); pmn.pop();
        b *= pmn.top(); pmn.pop();
        int ans = pmn.top(); pmn.pop();
        return max(ans * a, ans * b);
    }
};