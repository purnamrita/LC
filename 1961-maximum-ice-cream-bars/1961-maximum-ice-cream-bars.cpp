class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        int sum = 0;
        int n = costs.size();

        for(int i = 0; i < n; i++){
            sum += costs[i];
            cnt++;

            if(sum == coins){
                return cnt;
            }
            if(sum > coins){
                return cnt - 1;
            }
        }

        return cnt;
    }
};