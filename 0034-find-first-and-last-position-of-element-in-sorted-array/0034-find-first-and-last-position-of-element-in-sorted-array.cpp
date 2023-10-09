class Solution {
public:
    int firstOcc(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
    
    int lastOcc(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high =  mid - 1;
            } 
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return {-1, -1};
        }
        return {firstOcc(nums, target), lastOcc(nums, target)};
    }
};