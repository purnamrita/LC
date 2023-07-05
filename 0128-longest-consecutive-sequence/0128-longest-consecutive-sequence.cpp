class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        unordered_set<int> s;
        for(int ele : nums){
            s.insert(ele);
        }
        int ans = 1;
        for(auto ele : s){
            if(s.find(ele - 1) != s.end()){
                continue;
            }
            else{
                int curr = 0;
                while(s.find(ele) != s.end()){
                    curr++;
                    ele += 1;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};