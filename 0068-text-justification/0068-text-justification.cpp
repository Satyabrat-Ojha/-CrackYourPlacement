class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string>> lines;
        vector<int> spaces;
        createLines(words, maxWidth, lines);
        createSpaces(maxWidth, spaces, lines);

        vector<string> res(lines.size(), "");
        
        for(int i=0;i<lines.size()-1;i++) {
            res[i] += lines[i][0];
            double space = spaces[i];
            int d = lines[i].size() - 1;
            
            for(int j=1;j<lines[i].size();j++) {
                int x = ceil(space / d);
                space -= x;
                d--;
                while(x--) res[i].push_back(' ');
                res[i] += lines[i][j];
            }
        }

        for(auto word : lines.back()) res.back() += word + " ";
        res.back().pop_back();
        for(auto &r:res)
            while(r.size() < maxWidth) 
                r.push_back(' ');
        
        return res;
    }

    void createLines(vector<string>& words, int w, vector<vector<string>>& lines) {
        int l = 0;
        for(auto word:words) {
            if(word.size() < l) {
                lines.back().push_back(word);
                l -= word.size() + 1;
            }
            else {
                lines.push_back({word});
                l = w - word.size();
            }
        }
    }

    void createSpaces(int w, vector<int>& spaces, vector<vector<string>>& lines) {
        for(auto line:lines) {
            int x = w;
            for(auto word:line) x -= word.size();
            spaces.push_back(x);
        }
    }
};