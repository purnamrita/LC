class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            int target = -(nums[i]);
            int lo = i + 1;
            int hi = n - 1;

            while(lo < hi){
                if(nums[lo] + nums[hi] == target){
                    vector<int> temp = {nums[i], nums[lo], nums[hi]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                    lo++;
                    while(lo < hi && nums[lo] == nums[lo - 1]){
                        lo++;
                    }
                    hi--;
                    while(lo < hi && nums[hi] == nums[hi + 1]){
                        hi--;
                    }
                }
                else if(nums[lo] + nums[hi] < target){
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

        for(auto v : s){
            ans.push_back(v);
        }

        return ans;
    }
};