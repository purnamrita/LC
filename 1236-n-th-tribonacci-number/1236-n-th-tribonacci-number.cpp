class Solution {
public:
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1 || n == 2){
            return 1;
        }
        int prevvv = 0;
        int prevv = 1;
        int prev = 1;
        int curr;
        
        for(int i = 3; i <= n; i++){
            curr = prevvv + prevv + prev;
            prevvv = prevv;
            prevv = prev;
            prev = curr;
        }

        return curr;
    }
};