class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int rn = n - k;
        int total_sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int l = 0;
        int r = rn - 1;
        int sum = accumulate(cardPoints.begin() + l, cardPoints.begin() + r + 1, 0);
        int mini = sum;
        r++;
        while(r < n){
            sum += cardPoints[r];
            sum -= cardPoints[l];
            mini = min(mini, sum);
            r++;
            l++;
        }

        return total_sum - mini;
    }
};