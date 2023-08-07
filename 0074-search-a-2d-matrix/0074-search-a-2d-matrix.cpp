class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int top = 0;
        int bot = n - 1;

        while(top <= bot){
            int mid = top + (bot - top) / 2;
            if(target > matrix[mid][m - 1]){
                top = mid + 1;
            }
            else if(target < matrix[mid][0]){
                bot = mid - 1;
            }
            else{
                break;
            }
        }

        if(top > bot){
            return false;
        }

        int row = top + (bot - top) / 2;

        int l = 0;
        int r = m - 1;

        while(l <= r){
            int m = l + (r - l) / 2;
            if(matrix[row][m] > target){
                r = m - 1;
            }
            else if(matrix[row][m] < target){
                l = m + 1;
            }
            else{
                return true;
            }
        }

        return false;
    }
};