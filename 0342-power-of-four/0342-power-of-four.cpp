class Solution {
public:
    bool isPowerOfFour(int n) {
        double number = n;
        double base = 4.0;
        double res = log(number) / log(base);

        return n > 0 && fmod(res, 1.0) == 0.0;
    }
};