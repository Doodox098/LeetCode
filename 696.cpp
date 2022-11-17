class Solution {
public:
    int countBinarySubstrings(string s) {
        char d = s[0];
        int k = 0;
        int l = 1, c = 0;
        for(int i = 1; i < size(s); i++){
            if(s[i] != d){
                d = s[i];
                if(c >= l){
                    k += l;
                }
                else{
                    k += c;
                }
                c = l;
                l = 1;
            }
            else{
                l++;
            }
        }
        if(c >= l){
            k += l;
        }
        else{
            k += c;
        }
        return k;
    }
};
