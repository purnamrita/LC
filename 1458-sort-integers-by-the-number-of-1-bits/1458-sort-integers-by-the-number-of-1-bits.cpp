class Solution {
public:
    static int count1Bits(int n){
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if((n & (1 << i)) != 0){
                ans++;
            }
        }
        return ans;
    }

    static bool comparator(int num1, int num2){
        int cnt11 = count1Bits(num1);
        int cnt12 = count1Bits(num2);

        if(cnt11 == cnt12){
            return (num1 < num2);
        }
        return (cnt11 < cnt12);
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comparator);

        return arr;
    }
};