class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2 * k + 1, 0);

        for(int idx = n - 1; idx >= 0; idx--){
            vector<int> curr(2*k + 1, 0);
            for(int trans = 2*k - 1; trans >= 0; trans--){
                if(trans % 2 == 0){
                    //buy
                    curr[trans] = max(
                        -prices[idx] + after[trans + 1],
                        after[trans]
                    );
                }
                else{
                    //sell
                    curr[trans] = max(
                        prices[idx] + after[trans + 1],
                        after[trans]
                    );
                }
            }
            after = curr;
        }

        return after[0];
    
    }
};