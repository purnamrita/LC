class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int afterr = 0;
        int after = 0;
        int curr;
        
        for(int i = n - 1; i >= 0; i--){
            curr = cost[i] + min(after, afterr);
            afterr = after;
            after = curr;
        }

        return min(after, afterr);
    }
};