class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        map<int, unordered_set<char>> rmap;
        map<int, unordered_set<char>> cmap;
        map<pair<int, int>, unordered_set<char>> cblock;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char ele = board[i][j];
                if(ele == '.'){
                    continue;
                }
                else{
                    if(rmap[i].find(ele) != rmap[i].end() ||
                        cmap[j].find(ele) != cmap[j].end() ||
                        cblock[{i/3, j/3}].find(ele) != cblock[{i/3, j/3}].end()
                    )
                    {
                        return false;
                    }
                    rmap[i].insert(ele);
                    cmap[j].insert(ele);
                    cblock[{i/3, j/3}].insert(ele);
                }
            }
        }

        return true;
    }
};