class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int x=a.size()-1,y=b.size()-1,c=0;
        while(x>=0 && y>=0)
        {
            int n=a[x]+b[y]-96+c;
            if(n>1) c=1;
            else c=0;
            if(n%2) ans+="1";
            else ans+="0";
            x--; y--;
        }
        while(x>=0){
            int n=c+a[x]-48;
            if(n>1) c=1;
            else c=0;
            if(n%2) ans+="1";
            else ans+="0";
            x--;
        }
        while(y>=0){
            int n=c+b[y]-48;
            if(n>1) c=1;
            else c=0;
            if(n%2) ans+="1";
            else ans+="0";
            y--;
        }
        if(c==1) ans+="1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};