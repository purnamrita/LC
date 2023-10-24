class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2;

        vector<vector<int>> after(2, vector<int>(cap + 1, 0));
        
        for(int idx = n - 1; idx >= 0; idx--){
            vector<vector<int>> curr(2, vector<int>(cap + 1, 0));
            for(int buy = 0; buy < 2; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    if(buy == 1){
                        curr[buy][cap] = max(
                            -prices[idx] + after[0][cap],
                            after[1][cap]
                        );
                    }
                    else{
                        curr[buy][cap] = max(
                            prices[idx] + after[1][cap - 1],
                            after[0][cap]
                        );
                    }
                }
            }
            after = curr;
        }

        return after[1][2];
    }
};