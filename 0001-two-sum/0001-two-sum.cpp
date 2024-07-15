class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;

        for(int i=0;i<nums.size();i++) {
            if(m.find(nums[i]) != m.end()) {
                return {m[nums[i]], i};
            }
            m[target - nums[i]] = i;
        }

        return {-1,-1};
    }
};