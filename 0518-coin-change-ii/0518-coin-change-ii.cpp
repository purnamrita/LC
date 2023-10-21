class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for(int amt = 0; amt <= amount; amt++){
            dp[0][amt] = (amt % coins[0] == 0);
        }

        for(int row = 1; row < n; row++){
            for(int amt = 0; amt <= amount; amt++){ 
                int notTake = dp[row - 1][amt];
                int take = 0;
                if(coins[row] <= amt){
                    take = dp[row][amt - coins[row]];
                }
                dp[row][amt] = take + notTake;
            }
        }

        return dp[n - 1][amount];
    }
};