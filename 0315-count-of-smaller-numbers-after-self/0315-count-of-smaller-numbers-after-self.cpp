class BIT {
    vector<int> bit;
public:
    BIT(int size = 0) {
        bit.assign(size+1, 0);
    }

    void addValue(int idx, int val) {
        for(; idx < bit.size() ; idx += idx & -idx)
            bit[idx] += val;
    }

    int getSum(int idx) {
        int sum = 0;
        for(; idx > 0 ; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(auto &num:nums) num += 1e4 + 1;
        BIT bit = BIT(2 * 1e4 + 1);
        for(int i=n-1;i>=0;i--) {
            bit.addValue(nums[i], 1);
            ans[i] = bit.getSum(nums[i] - 1);
        }
        return ans;
    }
};