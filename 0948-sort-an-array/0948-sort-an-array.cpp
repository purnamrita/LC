class Solution {
public:
    vector<int> merge(vector<int> v1, vector<int> v2){
        int n1 = v1.size();
        int n2 = v2.size();
        int i = 0;
        int j = 0;
        vector<int> res;

        while(i < n1 && j < n2){
            if(v1[i] <= v2[j]){
                res.push_back(v1[i]);
                i++;
            }
            else if(v1[i] > v2[j]){
                res.push_back(v2[j]);
                j++;
            }
        }

        while(i < n1){
            res.push_back(v1[i]);
            i++;
        }
        while(j < n2){
            res.push_back(v2[j]);
            j++;
        }

        return res;
    }

    vector<int> mergeSort(vector<int>& nums, int s, int e){
        if(s == e){
            return {nums[s]};
        }
        int mid = s + (e - s) / 2;
        vector<int> leftArr = mergeSort(nums, s, mid);
        vector<int> rightArr = mergeSort(nums, mid + 1, e);
        return merge(leftArr, rightArr);

    }

    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};