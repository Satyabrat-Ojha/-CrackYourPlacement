class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        for(int i=1;i<nums.size();i++) nums[i]+=nums[i-1];
        map<int,int> m;
        m[0]++;
        int ans = 0;
        for(auto num:nums) {
            ans += m[num-k];
            m[num]++;
        }
        return ans;
    }
};