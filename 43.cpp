class Solution {
public:
    string multiply(string num1, string num2) {
        string num;
        if(num1[0] == '0' || num2[0] == '0')return "0";
        int l1 = num1.length();
        int l2 = num2.length();
        int n = l1 + l2 - 1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int d1 = 0; d1 <= i && d1 < l1; d1++){
                if(i - d1 < l2)
                    sum += ((num1[l1 - d1 - 1] - '0') * (num2[l2 - i + d1 - 1] - '0'));
            }
            num = (char)(sum % 10 + '0') + num;
            sum = sum / 10;
        }
        while(sum > 0){
            num = (char)(sum % 10 + '0') + num;
            sum /= 10;
        }
        return num;
    }
};
