class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2 ;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }

    int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        int cnt = count(arr,low,mid,high);

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) temp.push_back(arr[left++]);
            else temp.push_back(arr[right++]);
        }

        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++) arr[i] = temp[i - low];
        return cnt;
    }

    int count(vector<int> &arr, int low, int mid, int high) {
        int ans=0,count=0;
        for(int i=low;i<=mid;i++) {
            for(int j=mid+1+count;j<=high;j++) {
                if((long)arr[i]>(long)2*arr[j]) count++;
                else break;
            }
            ans+=count;
        }
        return ans;
    }
};