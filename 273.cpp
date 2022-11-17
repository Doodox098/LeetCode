class Solution {
private:
    string h(int num){
        string s = "";
        if(num / 100 > 0)s += u(num / 100) + "Hundred ";
        if(num % 100 > 0)s += d(num % 100);
        return s;
    }
    string d(int num){
        string s = "";
        if(num > 9 && num < 20){
            switch(num){
                case 10:
                    return "Ten ";
                case 11:
                    return "Eleven ";
                case 12:
                    return "Twelve ";
                case 13:
                    return "Thirteen ";
                case 14:
                    return "Fourteen ";
                case 15:
                    return "Fifteen ";
                case 16:
                    return "Sixteen ";
                case 17:
                    return "Seventeen ";
                case 18:
                    return "Eighteen ";
                case 19:
                    return "Nineteen ";
                default:
                    return "";
        }
        }
        else{
            switch(num / 10){
                case 2:
                    s += "Twenty ";
                    break;
                case 3:
                    s += "Thirty ";
                    break;
                case 4:
                    s += "Forty ";
                    break;
                case 5:
                    s += "Fifty ";
                    break;
                case 6:
                    s += "Sixty ";
                    break;
                case 7:
                    s += "Seventy ";
                    break;
                case 8:
                    s += "Eighty ";
                    break;
                case 9:
                    s += "Ninety ";
                    break;
                default:
                    s += "";
                    break;
            }
            s += u(num % 10);
        }
        return s;
    }
    string u(int num){
        switch(num){
            case 1:
                return "One ";
            case 2:
                return "Two ";
            case 3:
                return "Three ";
            case 4:
                return "Four ";
            case 5:
                return "Five ";
            case 6:
                return "Six ";
            case 7:
                return "Seven ";
            case 8:
                return "Eight ";
            case 9:
                return "Nine ";
            default:
                return "";
        }
    }
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string s = "";
        int d = 1000000000;
        if(num / d > 0)s = s + u(num / d) + "Billion ";
        num = num % d;
        d = d / 1000;
        if(num / d > 0)s = s + h(num / d) + "Million ";
        num = num % d;
        d = d / 1000;
        if(num / d > 0)s = s + h(num / d) + "Thousand ";
        num = num % d;
        if(num > 0)s += h(num);
        if(s != "")s.pop_back();
        return s;
    }
};
