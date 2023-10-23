class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        
        vector<double> prev(tlen + 1, 0);
        prev[0] = 1;

        for(int i = 1; i <= slen; i++){
            for(int j = tlen; j >= 1; j--){
                if(s[i - 1] == t[j - 1]){
                    prev[j] = prev[j - 1] + prev[j];
                }
                else{
                    prev[j] = prev[j];
                }
            }
        }

        return (int)prev[tlen];
    }
};