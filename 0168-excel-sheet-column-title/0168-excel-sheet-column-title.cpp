class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while(columnNumber){
            int rem = columnNumber % 26;
            if(rem == 0){
                ans = 'Z' + ans;
                columnNumber = columnNumber/26 - 1;
            }
            else{
                char c = 'A' + rem - 1;
                ans = c + ans;
                columnNumber = columnNumber/26;
            }
        }

        return ans;
    }
};