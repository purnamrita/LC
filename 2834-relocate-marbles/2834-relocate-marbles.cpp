class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> s(nums.begin(), nums.end());

        int n = moveFrom.size();
        for(int i = 0; i < n; i++){
            int src = moveFrom[i];
            int dest = moveTo[i];

            if(s.find(src) == s.end()){
                continue;
            }
            else{
                s.erase(src);
                s.insert(dest);
            }
        }

        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};