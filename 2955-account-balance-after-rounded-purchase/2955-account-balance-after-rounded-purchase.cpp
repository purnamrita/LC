class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int to_sub;
        int cnt = 0;
        while(purchaseAmount % 10){
            cnt++;
            purchaseAmount++;
        }
        if(cnt <= 5){
            return 100 - purchaseAmount;
        }
        return 100 - (purchaseAmount - 10);
    }
};