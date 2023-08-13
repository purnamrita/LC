class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0;
        sort(cost.begin(), cost.end());
        int j = cost.size() - 1;
        while(j >= 0){
            int cost1 = cost[j];
            j--;
            int cost2 = 0;
            if(j >= 0){
                cost2 = cost[j]; 
            }
            j -= 2;
            ans += (cost1 + cost2);
        }
        return ans;
    }
};