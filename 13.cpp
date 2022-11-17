class Solution {
public:
    int romanToInt(string s) {
        char a[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int n[] = {1000, 500, 100, 50, 10, 5, 1};
        int sum = 0;
        int i = 0;
        int j = 0;
        while(s[i] != 0){
            if(s[i] == a[j]){
                sum += n[j];
                i++;
            }
            else if(j > 0 && s[i] == a[j - 1]){
                sum += (n[j - 1] - 2 * n[j]);
                i++;
            }
            else if(j > 1 && s[i] == a[j - 2]){
                sum += (n[j - 2] - 2 * n[j]);
                i++;
            }
            else j++;
        }
        return sum;
    }
};
