//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{   
	    int n = nums.size();
	    vector<pair<int,int>> v;
	    for(int i=0;i<n;i++) v.push_back({nums[i],i});
	    sort(v.begin(),v.end());
	    
	    int ans = 0;
	    vector<bool> vis(n);
	    for(int i=0;i<n;i++) {
	        if(!vis[i]) ans += dfs(i, v, vis);
	    }
	    return ans;
	}
	
	int dfs(int i, vector<pair<int,int>>& v, vector<bool>& vis) {
	    if(vis[i]) return -1;
	    vis[i] = 1;
	    return 1 + dfs(v[i].second, v, vis);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends