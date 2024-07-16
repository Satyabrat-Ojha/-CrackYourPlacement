class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        int n=s.size();
        for(int i=0;i<n;i++) {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') a.push(s[i]);
            else if(a.size()==0) return 0;
            else if(a.top()=='(' && s[i]==')') a.pop();
            else if(a.top()=='[' && s[i]==']') a.pop();
            else if(a.top()=='{' && s[i]=='}') a.pop();
            else return 0;
        }
        if(a.size()==0) return 1;
        return 0;
    }
};