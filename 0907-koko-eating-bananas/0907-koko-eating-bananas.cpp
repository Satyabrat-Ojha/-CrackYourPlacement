class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1e9;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(check(mid, h, piles)) high = mid;
            else low = mid + 1;
        }
        return high;
    }

    bool check(int s, int h, vector<int> &piles) {
        int ans = 0;
        for(auto &pile:piles) {
            ans += pile/s;
            if(pile%s) ans++;
            if(ans > h) return 0;
        }
        return 1;
    }
};