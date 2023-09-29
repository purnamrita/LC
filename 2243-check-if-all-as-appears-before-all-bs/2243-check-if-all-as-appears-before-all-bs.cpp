class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        char prev = s[0];

        for(int i = 1; i < n; i++){
            if(prev == 'b' && s[i] == 'a'){
                return false;
            }
            prev = s[i];
        }

        return true;
    }
};