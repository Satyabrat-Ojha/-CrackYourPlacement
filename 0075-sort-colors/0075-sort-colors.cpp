class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st = 0, en = nums.size()-1;
        for(int i=0;i<=en;i++) {
            if(nums[i]==0) {
                swap(nums[i],nums[st]);
                st++;
            }
            else if(nums[i]==2) {
                swap(nums[i],nums[en]);
                i--;
                en--;
            }
        }
    }
};