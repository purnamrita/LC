class Solution {
public:
    int firstOcc(vector<int> &arr, int target){
        int n = arr.size();
        int idx = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        if(idx != n && arr[idx] == target){
            return idx;
        }
        return -1;
    }
    int lastOcc(vector<int> &arr, int target){
        int n = arr.size();
        int idx = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        if(idx != 0 && arr[idx - 1] == target){
            return idx - 1;
        }
        return -1;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int firstIdx = firstOcc(nums, target);
        int lastIdx = lastOcc(nums, target);
        if(firstIdx == -1){
            return ans;
        }
        for(int i = firstIdx; i <= lastIdx; i++){
            ans.push_back(i);
        }
        return ans;
    }
};