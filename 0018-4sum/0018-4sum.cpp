class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n < 4){
            return ans;
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }

                int lo = j + 1;
                int hi = n - 1;
                long long req = target - nums[i];
                req = req - nums[j];

                while(lo < hi){
                    long long sum = nums[lo];
                    sum += nums[hi];
                    
                    if(sum == req){
                        ans.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        lo++;
                        hi--;
                        while(lo < hi && nums[lo] == nums[lo - 1]){
                            lo++;
                        }
                        while(lo < hi && nums[hi] == nums[hi + 1]){
                            hi--;
                        }
                    }
                    else if(sum < req){
                        lo++;
                        while(lo < hi && nums[lo] == nums[lo - 1]){
                            lo++;
                        }
                    }
                    else{
                        hi--;
                        while(lo < hi && nums[hi] == nums[hi + 1]){
                            hi--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};