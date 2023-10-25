class Solution {
public:
    int helper(int idx, vector<int>& days, vector<int>& costs, vector<int> &dp){
        int n = days.size();
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        // 1 day
        int op1 = costs[0] + helper(idx + 1, days, costs, dp);

        //7 days
        int i;
        for(i = idx; i < n && days[i] < days[idx] + 7; i++);
        int op2 = costs[1] + helper(i, days, costs, dp);

        //30 days
        for(i = idx; i < n && days[i] < days[idx] + 30; i++);
        int op3 = costs[2] + helper(i, days, costs, dp);

        return dp[idx] = min(op1, min(op2, op3));

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, -1);
        return helper(0, days, costs, dp);
    }
};