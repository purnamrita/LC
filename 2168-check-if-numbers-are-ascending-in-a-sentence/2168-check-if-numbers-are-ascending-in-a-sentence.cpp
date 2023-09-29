class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = -1;
        int curr = -1;
        int n = s.length();

        for(int i = 0; i < n; i++){
            prev = curr;
            if(s[i] >= '0' && s[i] <= '9'){
                string temp = "";
                while(s[i] >= '0' && s[i] <= '9' && i < n){
                    temp += s[i];
                    i++;
                }
                curr = stoi(temp);
                if(prev != -1){
                    if(curr <= prev){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};