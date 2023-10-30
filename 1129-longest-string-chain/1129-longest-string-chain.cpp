class Solution {
public:
    bool compare(string &big, string &small){
        int n = big.size();
        if(big.length() != 1 + small.length()){
            return false;
        }
        int bp = 0;
        int sp = 0;

        while(bp < big.size()){
            if(big[bp] == small[sp]){
                bp++;
                sp++;
            }
            else{
                bp++;
            }
        }
        return (bp == big.size() && sp == small.size());
    }

    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n = words.size();

        vector<int> dp(n, 1);
        int maxLen = 1;

        for(int idx = 1; idx < n; idx++){
            for(int prev = 0; prev < idx; prev++){
                if(compare(words[idx], words[prev]) && dp[idx] < dp[prev] + 1){
                    dp[idx] = dp[prev] + 1;
                }
            }
            if(dp[idx] > maxLen){
                maxLen = dp[idx];
            }
        }

        return maxLen;
    }
};