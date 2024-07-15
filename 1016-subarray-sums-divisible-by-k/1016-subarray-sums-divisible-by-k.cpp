class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>m;
        m[0] = 1;
        int ans=0;
        for(int i=1;i<nums.size();i++) nums[i]%=k;
        for(int i=1;i<nums.size();i++) nums[i]=(nums[i]+nums[i-1])%k;
        for(auto a:nums) m[modulo(a,k)]++;
        for(int i=0;i<k;i++) ans+=m[i]*(m[i]-1)/2;
        return ans;
    }

    int modulo(int a,int b) {
        return (a%b+b)%b;
    }
};