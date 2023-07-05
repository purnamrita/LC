class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m + n);
        int i = 0;
        int j = 0;
        int idx = 0;

        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                temp[idx] = nums1[i];
                i++;
                idx++;
            }
            else{
                temp[idx] = nums2[j];
                j++;
                idx++;
            }
        }

        while(i < m){
            temp[idx] = nums1[i];
            i++;
            idx++;
        }

        while(j < n){
            temp[idx] = nums2[j];
            j++;
            idx++;
        }
        
        for(int i = 0; i < m + n; i++){
            nums1[i] = temp[i]; 
        }
    }
};