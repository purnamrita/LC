class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int time = minutesToTest / minutesToDie;
        return ceil((log2(buckets)) / (log2(time + 1)));
    }
};