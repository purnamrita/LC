class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int alice = 0;
        int bob = 0;
        int l = 0;
        int cnt = 1;
        
        for(int r = 1; r < n; r++){
            if(colors[l] != colors[r]){
                if(colors[l] == 'A' && cnt >= 3){
                    alice += (cnt - 2);
                }
                else if(cnt >= 3){
                    bob += (cnt - 2);
                }
                cnt = 1;
                l = r;

            }
            else{
                cnt++;
            }
        }
        if(colors[l] == 'A' && cnt >= 3){
            alice += (cnt - 2);
        }
        else if(cnt >= 3){
            bob += (cnt - 2);
        }

        return (alice > bob);
    }
};