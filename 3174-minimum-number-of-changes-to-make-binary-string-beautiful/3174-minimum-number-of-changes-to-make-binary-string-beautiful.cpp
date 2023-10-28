class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int i = 1;
        int cnt = 0;
        while(i < n){
            if(s[i] != s[i - 1]){
                cnt++;
            }
            i = i + 2;
        }
        return cnt;
    }
};