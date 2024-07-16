class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        if(!n) return 0;
        for(int i=0;i+n-1<haystack.size();i++){
            if(haystack.substr(i,n)==needle) return i;
        }
        return -1;
    }
};