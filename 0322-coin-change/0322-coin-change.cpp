class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for(int amt = 0; amt <= amount; amt++){
            if(amt % coins[0] == 0){
                dp[0][amt] = amt / coins[0];
            }
            else{
                dp[0][amt] = 1e9;
            }
        }

        for(int idx = 1; idx < n; idx++){
            for(int amt = 0; amt <= amount; amt++){
                int notPick = 0 + dp[idx - 1][amt];
                int pick = INT_MAX;
                if(coins[idx] <= amt){
                    pick = 1 + dp[idx][amt - coins[idx]];
                }
                dp[idx][amt] = min(pick, notPick);
            }

        }

        if(dp[n - 1][amount] == 1e9){
            return -1;
        }
        return dp[n - 1][amount];
    }
};