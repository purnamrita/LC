class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> front1(2, 0);
        vector<int> front2(2, 0);
        
        for(int idx = n - 1; idx >= 0; idx--){
            vector<int> curr(2, 0);
            for(int buy = 0; buy < 2; buy++){
                //buy
                curr[1] = max(
                    -prices[idx] + front1[0],
                    front1[1]
                );
                //sell
                curr[0] = max(
                    prices[idx] + front2[1],
                    front1[0]
                );
            }
            front2 = front1; 
            front1 = curr; 
        }

        return front1[1];
    }
};