class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        for(int i=1;i<n;i++) cardPoints[i] += cardPoints[i-1];
        int l = n - k;
        int m = (l==0) ? 0 : cardPoints[l-1];
        for(int i=l;i<n;i++) m = min(m, cardPoints[i] - cardPoints[i-l]);
        return cardPoints.back() - m;
    }
};