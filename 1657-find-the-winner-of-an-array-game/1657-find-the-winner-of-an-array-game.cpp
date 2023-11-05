class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int max_ele = *max_element(arr.begin(), arr.end());
        if(k >= n){
            return max_ele;
        }

        int curr_ele = arr[0];
        int curr_streak = 0;

        for(int i = 1; i < n; i++){
            if(curr_ele > arr[i]){
                curr_streak++;
            }
            else{
                curr_ele = arr[i];
                curr_streak = 1;
            }
            if(curr_streak == k || curr_ele == max_ele){
                return curr_ele;
            }
        }

        return curr_ele;

    }
};