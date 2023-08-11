class Solution {
public:
    bool isAlNum(char c){
        return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c<= '9'));
    }

    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while(l < r){
            while(!isAlNum(s[l]) && l < r){
                l++;
            }
            while(!isAlNum(s[r]) && l < r){
                r--;
            }
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};