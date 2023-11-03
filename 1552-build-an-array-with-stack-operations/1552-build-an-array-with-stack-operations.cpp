class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> ans;
        int sz = target.size();

        int ptr = 0;
        int i = 1;

        while(i <= n && ptr < sz){
            if(target[ptr] == i){
                ans.push_back("Push");
                ptr++;
                i++;
            }
            else if(target[ptr] > i){
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }
            else{
                ptr++;
            }
        }
        return ans;
    }
};