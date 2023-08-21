class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();

        for(int i = len / 2; i >= 1; i--){
            if(len % i == 0){
                int no_times_rep = len / i;
                string curr = "";
                for(int j = 0; j < no_times_rep; j++){
                    curr += s.substr(0, i);
                }
                if(curr == s){
                    return true;
                }
            }
        }

        return false;
    }
};