class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string res = "";
        int resLen = 0;

        for(int i = 0; i < n; i++){
            // odd length palindrome
            int l = i;
            int r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                int currLen = r - l + 1;
                if(currLen > resLen){
                    res = s.substr(l, currLen);
                    resLen = currLen;
                }
                l--;
                r++;
            }

            // even length palindrome
            l = i;
            r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                int currLen = r - l + 1;
                if(currLen > resLen){
                    res = s.substr(l, currLen);
                    resLen = currLen;
                }
                l--;
                r++;
            }
        }

        return res;

    }
};