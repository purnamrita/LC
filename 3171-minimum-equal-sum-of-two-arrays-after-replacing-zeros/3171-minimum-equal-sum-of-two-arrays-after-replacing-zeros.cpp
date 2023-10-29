class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        for(int i = 0; i < nums1.size(); i++){
            sum1 += max(1, nums1[i]);
            if(nums1[i] == 0){
                cnt1++;
            }
        }

        for(int i = 0; i < nums2.size(); i++){
            sum2 += max(1, nums2[i]);
            if(nums2[i] == 0){
                cnt2++;
            }
        }

        if(sum1 < sum2 && cnt1 == 0){
            return -1;
        }
        if(sum2 < sum1 && cnt2 == 0){
            return -1;
        }
        return max(sum1, sum2);
    }
};