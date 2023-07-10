class Solution {
public:
    string toLowerCase(string s) {
        int n = s.length();
        string ans = "";
        for(int i = 0; i < n; i++){
            s[i] = tolower(s[i]);;
        }
        return s;
    }
};