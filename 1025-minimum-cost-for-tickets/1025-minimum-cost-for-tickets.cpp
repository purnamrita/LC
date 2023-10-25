class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);
        
        for(int idx = n - 1; idx >= 0; idx--){
            // 1 day
            int op1 = costs[0] + dp[idx + 1];

            //7 days
            int i;
            for(i = idx; i < n && days[i] < days[idx] + 7; i++);
            int op2 = costs[1] + dp[i];

            //30 days
            for(i = idx; i < n && days[i] < days[idx] + 30; i++);
            int op3 = costs[2] + dp[i];

            dp[idx] = min(op1, min(op2, op3));
        }

        return dp[0];
    }
};