class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> count(26);
        int ans = INT_MIN;

        int start = 0;
        int end = 0;

        int maxChar = 0;

        while(end < n){
            count[s[end] - 'A']++;

            maxChar = max(maxChar, count[s[end] - 'A']);


            if((end - start + 1) - maxChar > k){
                count[s[start] - 'A']--;
                start++;
            }
            ans = max(ans, end - start + 1);
            end++;
        }

        return ans;
    }
};