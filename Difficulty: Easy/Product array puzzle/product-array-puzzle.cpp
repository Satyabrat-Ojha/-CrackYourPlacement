//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
#define ll long long

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<ll> v(nums.size());
        
        ll z = 0, p = 1;
        for(auto num:nums) z += !num;
        if(z > 1) return v;
        for(auto num:nums) if(num) p*=num;
        
        if(z == 1) {
            for(int i=0;i<nums.size();i++) if(!nums[i]) v[i] = p;
            return v;
        }
        
        for(int i=0;i<nums.size();i++) v[i] = p/nums[i];
        return v;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends