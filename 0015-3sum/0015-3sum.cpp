class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int l = i + 1;
            int r = n - 1;
            int target = -nums[i];

            while(l < r){
                int sum = nums[l] + nums[r];

                if(sum == target){
                    vector<int> temp = {nums[i], nums[l], nums[r]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                    l++;
                    r--;
                }
                else if(sum < target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }

        vector<vector<int>> ans;

        for(auto v : s){
            ans.push_back(v);
        }

        return ans;
    }
};