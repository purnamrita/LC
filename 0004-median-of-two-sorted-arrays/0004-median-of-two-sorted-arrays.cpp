class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int ptr1 = 0;
        int ptr2 = 0;
        int idx1 = n / 2;
        int idx2 = idx1 - 1;
        int ele1 = INT_MAX;
        int ele2 = INT_MAX;
        int cnt = 0;

        while(ptr1 < n1 && ptr2 < n2){
            if(nums1[ptr1] <= nums2[ptr2]){
                if(cnt == idx1){ele1 = nums1[ptr1];}
                if(cnt == idx2){ele2 = nums1[ptr1];}
                ptr1++;
                cnt++;
            }
            else{
                if(cnt == idx1){ele1 = nums2[ptr2];}
                if(cnt == idx2){ele2 = nums2[ptr2];}
                ptr2++;
                cnt++;
            }
            if(ele1 != INT_MAX && ele2 != INT_MAX){
                break;
            }
        }
        while(ptr1 < n1){
            if(cnt == idx1){ele1 = nums1[ptr1];}
            if(cnt == idx2){ele2 = nums1[ptr1];}
            ptr1++;
            cnt++;
            if(ele1 != INT_MAX && ele2 != INT_MAX){
                break;
            }
        }
        while(ptr2 < n2){
            if(cnt == idx1){ele1 = nums2[ptr2];}
            if(cnt == idx2){ele2 = nums2[ptr2];}
            ptr2++;
            cnt++;
            if(ele1 != INT_MAX && ele2 != INT_MAX){
                break;
            }
        }
        if(n % 2){
            return ele1;
        }
        return ((double)ele1 + (double)ele2) / 2.0;
    }
};