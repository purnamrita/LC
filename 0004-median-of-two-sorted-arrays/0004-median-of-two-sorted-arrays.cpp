class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int ptr1 = 0;
        int ptr2 = 0;
        vector<int> nums;

        while(ptr1 < n1 && ptr2 < n2){
            if(nums1[ptr1] <= nums2[ptr2]){
                nums.push_back(nums1[ptr1]);
                ptr1++;
            }
            else{
                nums.push_back(nums2[ptr2]);
                ptr2++;
            }
        }
        while(ptr1 < n1){
            nums.push_back(nums1[ptr1]);
            ptr1++;
        }
        while(ptr2 < n2){
            nums.push_back(nums2[ptr2]);
            ptr2++;
        }

        int sum = 0;
        if(n % 2){
            return nums[n / 2];
        }
        sum += (double)(nums[n / 2] + nums[n / 2 - 1]);
        return sum / 2.0;
    }
};