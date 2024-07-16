class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate("", 2*n, ans);
        return ans;
    }

    void generate(string s, int n, vector<string>& ans) {
        if(!n) {
            if(isValid(s)) ans.push_back(s);
            return;
        }

        generate(s+'(', n-1, ans);
        generate(s+')', n-1, ans);
    }

    bool isValid(string s) {
        stack<char> a;
        for(int i=0;i<s.size();i++) {
            if (s[i]=='(') a.push(s[i]);
            else if (a.size() && a.top()=='(' && s[i]==')') a.pop();
            else return 0;
        }
        return a.size()==0;
    }
};