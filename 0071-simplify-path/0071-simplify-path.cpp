class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v, s;
        comp(path, v);
        for(auto e:v) {
            if(e != "..") s.push_back(e);
            else if(!s.empty()) s.pop_back();
        }

        string res = "";
        for(auto e:s) res += "/" + e;
        return res == "" ? "/" : res;
    }

    void comp(string path, vector<string>& v) {
        if(path.empty()) return;
        if(path[0] == '/') {
            comp(path.substr(1), v);
            return;
        }
        string res = "";
        for(auto c : path) {
            if(c == '/') {
                if(res != ".") v.push_back(res);
                comp(path.substr(res.size()), v);
                return;
            }
            res += c;
        }
        if(res != ".") v.push_back(path);
    }
};