class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int to_sub = ((purchaseAmount + 5) / 10) * 10;
        return 100 - to_sub;
    }
};