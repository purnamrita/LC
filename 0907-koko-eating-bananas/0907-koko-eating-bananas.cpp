class Solution {
public:
    long long cntHours(vector<int>& piles, int rate){
        long long hrs = 0;
        for(int i = 0; i < piles.size(); i++){
            hrs += ceil((double)piles[i] / (double)rate);
        }
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int hr) {
        int maxi = *max_element(piles.begin(), piles.end());

        int l = 1;
        int h = maxi;
        int ans;

        while(l <= h){
            int m = l + (h - l) / 2;
            long long hrs = cntHours(piles, m);
            if(hrs > hr){
                l = m + 1;
            }
            else{
                ans = m;
                h = m - 1;
            }
        }

        return ans;

    }
};