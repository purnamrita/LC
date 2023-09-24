class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            int start = nums[i][0];
            int end = nums[i][1];

            for(int i = start; i <= end; i++){
                if(s.find(i) == s.end()){
                    s.insert(i);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};