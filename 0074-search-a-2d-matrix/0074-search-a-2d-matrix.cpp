class Solution {
public:
    bool bs(vector<int> v, int l, int h, int target){
        while(l <= h){
            int m = l + (h - l) / 2;
            if(v[m] == target){
                return true;
            }
            else if(v[m] > target){
                h = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++){
            if(matrix[i][0] <= target && target <= matrix[i][n - 1]){
                if(bs(matrix[i], 0, n - 1, target) == true){
                    return true;
                }
                break;
            }
        }

        return false;
    }
};