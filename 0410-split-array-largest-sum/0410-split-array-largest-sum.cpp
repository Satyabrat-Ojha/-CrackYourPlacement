class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0LL);
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(duable(mid, m, nums)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    bool duable(int mx, int m, vector<int>& nums) {
        int sum = 0;
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