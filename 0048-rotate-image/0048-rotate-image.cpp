class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose then rotate the individual rows
        int rows = matrix.size();
        int cols = matrix[0].size();


        //transpose
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i > j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        //rotate individual rows
        for(int i = 0; i < rows; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};