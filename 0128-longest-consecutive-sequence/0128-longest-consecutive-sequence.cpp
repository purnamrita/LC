class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> s;

        for(int num : nums){
            s.insert(num);
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            int cnt = 0;
            if(s.find(nums[i] - 1) != s.end()){
                continue;
            }
            int number = nums[i];
            while(s.find(number) != s.end()){
                cnt++;
                number++;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};