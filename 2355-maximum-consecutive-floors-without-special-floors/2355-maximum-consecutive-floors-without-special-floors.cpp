class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();
        sort(special.begin(), special.end());
        int maxi = INT_MIN;

        maxi = max(maxi, special[0] - bottom);
        maxi = max(maxi, top - special[n - 1]);

        if(n == 1){
            return maxi;
        }

        for(int i = 1; i < n; i++){
            maxi = max(maxi, special[i] - special[i - 1] - 1);
        }
        return maxi;
    }
};