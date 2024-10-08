class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = min(height[l], height[r]) * (r - l);
        while(l < r) {
            (height[l] <= height[r]) ? l++ : r--;
            ans = max(ans, min(height[l], height[r]) * (r - l));
        }
        return ans;
    }
};