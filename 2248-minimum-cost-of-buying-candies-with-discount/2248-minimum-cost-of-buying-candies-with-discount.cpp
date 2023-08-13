class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int ans = 0;
        int n = cost.size();
        for(int i = 0; i < n; i++){
            if(i % 3 != n % 3){
                ans += cost[i];
            }
        }
        return ans;
    }
};