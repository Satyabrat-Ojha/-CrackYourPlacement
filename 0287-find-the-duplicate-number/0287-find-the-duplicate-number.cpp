class Solution {
public:
    int findDuplicate(vector<int> nums) {
        for(int i=0;i<nums.size();i++) {
            int c=abs(nums[i]);
            if(nums[c]<0) return abs(nums[i]);
            nums[c]*=(-1);
        }
        return -1;
    }
};