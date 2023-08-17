class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;

        for(int i = 0; i < n; i++){
            map<char, int> mp; //(char, int)
            for(int j = i; j < n; j++){
                mp[s[j]]++;
                int low_f = INT_MAX;
                int high_f = 0;
                for(auto it : mp){
                    low_f = min(low_f, it.second);
                    high_f = max(high_f, it.second);
                }
                ans += (high_f - low_f);
            }
        }

        return ans;
    }
};