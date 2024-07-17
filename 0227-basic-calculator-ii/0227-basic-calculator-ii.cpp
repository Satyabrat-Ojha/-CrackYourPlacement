class Solution {
public:
    int calculate(string s) {
        removeSpaces(s);
        vector<string> v;
        separate(s, v);
        
        stack<string> st;
        st.push(v[0]);
        for(int i=1;i<v.size();i+=2) {
            if(v[i] == "*" || v[i] == "/") {
                int x = stoi(st.top());
                st.pop();
                int y = stoi(v[i+1]);
                if(v[i] == "*") st.push(to_string(x*y));
                else st.push(to_string(x/y));
            }
            else {
                st.push(v[i]);
                st.push(v[i+1]);
            }
        }

        int ans = 0;
        while(!st.empty()) {
            cout<<st.top()<<" ";
            int x = stoi(st.top());
            st.pop();
            if(!st.empty() && st.top() == "-") x *= -1;
            if(!st.empty()) st.pop();
            ans += x;
        }
        return ans;
    }

    void separate(string s, vector<string>& v) {
        int a = 0, n = s.size();
        string res = "";
        for(int i=0;i<n;i++) {
            if(s[i] >= '0') res += s[i];
            else {
                v.push_back(res);
                res = "";
                res.push_back(s[i]);
                v.push_back(res);
                res.pop_back();
            }
        }
        if(!res.empty()) v.push_back(res);
    }
    
    void removeSpaces(string& s) {
        int idx = 0;
        for(auto &c:s) {
            if(c == ' ') continue;
            s[idx] = c;
            idx++;
        }
        while(s.size() > idx) s.pop_back();
    }
};