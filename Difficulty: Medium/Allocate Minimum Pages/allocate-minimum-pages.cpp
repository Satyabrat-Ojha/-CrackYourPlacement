//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(n < m) return -1;
        long long l = *max_element(arr, arr+n);
        long long r = accumulate(arr, arr+n, 0LL);
        while(l <= r) {
            long long mid = (l+r)/2;
            // cout<<mid<<" ";
            if(check(mid, n, arr, m)) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
    
    bool check(long long x, int n, int arr[], int m) {
        long long sum = 0;
        for(int i=0;i<n;i++) {
            sum += arr[i];
            if(sum > x) {
                sum = arr[i];
                m--;
            }
            if(!m) return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends