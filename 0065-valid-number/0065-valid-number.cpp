class Solution {
public:
    bool isNumber(string s) {
        int idx = 0;
        bool e = 0, d = 0;
        for(;idx<s.size();idx++) if(s[idx]=='e' || s[idx]=='E') { e = 1; break; } 
        string a = s.substr(0,idx), b = (idx >= s.size()-1) ? "" : s.substr(idx+1);
        if(e && (a.empty() || b.empty())) return 0;
        idx = 0;
        for(;idx<a.size();idx++) if(a[idx]=='.') { d = 1; break; }
        string a1 = a.substr(0,idx), a2 = (idx >= a.size()-1) ? "" : a.substr(idx+1);
        if(d && a1.empty() && a2.empty()) return 0;
        return validInteger(a1, 1, !a2.empty()) && validInteger(a2, 0, 0) && validInteger(b, 1, 0);
    }

    bool validInteger(string s, bool p, bool p2) {
        if(s.empty()) return 1;
        if(s == "+" || s == "-") return p2;
        if(s[0] == '+' || s[0] =='-') return (p) ? validInteger(s.substr(1), 0, 0) : 0;
        for(int i=0;i<s.size();i++) if(s[i] < '0' || s[i] > '9')  return 0;
        return 1;
    }
};