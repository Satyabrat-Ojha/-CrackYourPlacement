//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        for(int i=0;i<n;i++)
            if(arr[i] < 1 || arr[i] > n)
                arr[i] = 1e7;
        
        for(int i=0;i<n;i++)
        {
            int val = abs(arr[i]);
            if(val == 1e7) continue;
            arr[val-1] = -1 * abs(arr[val-1]);
        }
        
        int ans = 1;
        for(int i=0;i<n;i++) {
            if(arr[i] < 0) ans = i + 2;
            else break;
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends