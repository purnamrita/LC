class Solution {
public:
    int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        // unordered_map<char, vector<char>> mp;
        // mp[0] = {1, 2, 4};
        // mp[1] = {0, 2};
        // mp[2] = {1, 3};
        // mp[3] = {2};
        // mp[4] = {2, 3};

        //1 to n;
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));

        for(int col = 0; col < 5; col++){
            dp[1][col] = 1; 
        }

        for(int row = 2; row <= n; row++){
            
            dp[row][0] = (((dp[row - 1][1] % mod) + (dp[row - 1][2] % mod)) % mod + (dp[row - 1][4] % mod)) % mod;
            dp[row][1] = ((dp[row - 1][0] % mod) + (dp[row - 1][2] % mod)) % mod;
            dp[row][2] = ((dp[row - 1][1] % mod) + (dp[row - 1][3] % mod)) % mod;
            dp[row][3] = ((dp[row - 1][2] % mod)) % mod;
            dp[row][4] = ((dp[row - 1][2] % mod) + (dp[row - 1][3] % mod)) % mod;
        }

        int ans = 0;

        for(int col = 0; col < 5; col++){
            ans += dp[n][col];
            ans = ans % mod;
        }

        return ans;
    }
};