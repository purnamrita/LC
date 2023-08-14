class Solution {
public:
    void reverse(vector<int> &arr, int left, int right){
        while(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int d = (n - k % n) % n;
        reverse(nums, 0, d - 1);
        reverse(nums, d, n - 1);
        reverse(nums, 0, n - 1);
    }
};