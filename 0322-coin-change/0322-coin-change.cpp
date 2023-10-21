class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        vector<int> prev(amount + 1, 0);

        for(int amt = 0; amt <= amount; amt++){
            if(amt % coins[0] == 0){
                prev[amt] = amt / coins[0];
            }
            else{
                prev[amt] = 1e9;
            }
        }

        for(int idx = 1; idx < n; idx++){
            vector<int> curr(amount + 1, 0);
            for(int amt = 0; amt <= amount; amt++){
                int notPick = 0 + prev[amt];
                int pick = INT_MAX;
                if(coins[idx] <= amt){
                    pick = 1 + curr[amt - coins[idx]];
                }
                curr[amt] = min(pick, notPick);
            }
            prev = curr;

        }

        if(prev[amount] == 1e9){
            return -1;
        }
        return prev[amount];
    }
};