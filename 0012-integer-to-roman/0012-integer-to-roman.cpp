class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        int a[4] = {num%10, num%100/10, num%1000/100, num%10000/1000};
        
        // a[3]
        while (a[3]--) res += 'M';
        
        // a[2]
        if(a[2] == 4) res += "CD";
        else if(a[2] == 9) res +="CM";
        else {
            if(a[2] >= 5) { res += 'D'; a[2] -= 5; }
            while (a[2]--) res += 'C';
        }

        // a[1]
        if(a[1] == 4) res += "XL";
        else if(a[1] == 9) res += "XC";
        else {
            if(a[1] >= 5) { res += 'L'; a[1] -= 5; }
            while (a[1]--) res += 'X';
        }
        
        // a[0]
        if(a[0] == 4) res += "IV";
        else if(a[0] == 9) res += "IX";
        else {
            if(a[0] >= 5) { res += 'V'; a[0] -= 5; }
            while (a[0]--) res += 'I';
        }

        return res;
    }
};