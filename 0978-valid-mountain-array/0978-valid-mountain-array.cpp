class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3){
            return false;
        }

        if(arr[0] > arr[1]){
            return false;
        }

        int i;
        for(i = 1; i < n; i++){
            if(arr[i] > arr[i - 1]){
                continue;
            }
            else if(arr[i] == arr[i - 1]){
                return false;
            }
            else{
                break;
            }
        }
        if(i == n){
            return false;
        }
        int j;
        for(j = i; j < n; j++){
            if(arr[j] < arr[j - 1]){
                continue;
            }
            else{
                return false;
            }
        }
        if(j == n){
            return true;
        }
        return false;
    }
};