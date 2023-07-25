class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_set<int> s;

        for(int i = 0; i < n; i++){
            s.insert(nums[i]);
        }

        for(int i = 0; i < n; i++){
            if(s.find(nums[i] - 1) != s.end()){
                continue;
            }
            else{
                int cnt = 1;
                int num = nums[i];
                while(s.find(num + 1) != s.end()){
                    cnt++;
                    num = num + 1;
                }
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};