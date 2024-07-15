class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, element = 0;
        for(auto c:nums) {
            if(!count) {
                element = c;
                count++;
            }
            else if(c==element) count++;
            else count--;
        }
        return element;
    }
};