class Solution {
public:
    int maxConsecutiveChars(string answerKey, int k, char c){
        int n = answerKey.size();
        int ans = 0;
        int l = 0;
        int r = 0;
        int cntOther = 0;

        while(r < n){
            if(answerKey[r] != c){
                if(cntOther < k){
                    cntOther++;
                }
                else{
                    while(cntOther >= k){
                        if(answerKey[l] != c){
                            cntOther--;
                        }
                        l++;
                    }
                    cntOther++;
                }
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxT = maxConsecutiveChars(answerKey, k, 'T');
        int maxF = maxConsecutiveChars(answerKey, k, 'F');
        return max(maxT, maxF);
    }
};