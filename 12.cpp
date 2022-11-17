class Solution {
public:
    string intToRoman(int num) {
        char a[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int n[] = {1000, 500, 100, 50, 10, 5, 1};
        string s = "";
        int j = 0;
        while(num > 0){ 
            int cur = num / n[j];
            if(cur < 4 || j == 0)s += string(cur, a[j]);
            else if(cur < 6)s = s + string(5 - cur, a[j]) + a[j - 1];
            else if(cur < 9)s = s + a[j - 1] + string(cur - 5, a[j]);
            else s = s + a[j] + a[j - 2];
            num = num % n[j];
            j += 2;
        }
        return s;
    }
};
