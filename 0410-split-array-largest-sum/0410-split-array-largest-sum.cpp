class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long l = *max_element(nums.begin(),nums.end());
        long long r = accumulate(nums.begin(), nums.end(), 0LL);
        while(l < r) {
            long long mid = l + (r - l) / 2;
            if(duable(mid, m, nums)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    bool duable(long long mx, int m, vector<int>& nums) {
        long long sum = 0;
        for(int num : nums) {
            sum += num;
            if(sum > mx) {
                sum = num;
                m--;
            }
        }
        return m > 0;
    }
};