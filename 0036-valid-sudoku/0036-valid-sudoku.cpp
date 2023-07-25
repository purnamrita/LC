class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, vector<char> > row;
        map<int, vector<char> > col;

        map<pair<int, int>, vector<char>> square;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char ele = board[i][j];
                if(ele == '.'){
                    continue;
                }
                if(
                    (find(row[i].begin(), row[i].end(), ele) != row[i].end()) ||
                    (find(col[j].begin(), col[j].end(), ele) != col[j].end()) ||
                    (find(square[{i/3, j/3}].begin(), square[{i/3, j/3}].end(), ele) != square[{i/3, j/3}].end())
                    
                ){
                    return false;
                }

                row[i].push_back(ele);
                col[j].push_back(ele);
                square[{i / 3, j / 3}].push_back(ele);
            }
        }

        return true;
    }
};