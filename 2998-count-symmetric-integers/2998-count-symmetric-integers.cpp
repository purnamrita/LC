class Solution {
public:
    bool isValid(int num){
        string number = to_string(num);
        if(number.length() % 2){
            return false;
        }
        int lsum = 0;
        int rsum = 0;

        for(int i = 0; i < number.length() / 2; i++){
            lsum += int(number[i]);
        }
        for(int i = number.length() / 2; i < number.length(); i++){
            rsum += int(number[i]);
        }
        return lsum == rsum;
    }
    
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++){
            if(isValid(i)){
                cnt++;
            }
        }
        return cnt;
    }
};