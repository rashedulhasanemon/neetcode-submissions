class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<char>> index_row_map(9, std::unordered_set<char>(9));
        std::vector<std::unordered_set<char>> index_col_map(9, std::unordered_set<char>(9));
        std::vector<std::unordered_set<char>> index_sub_box(9, std::unordered_set<char>(9));

        int box_key = 0;
        size_t size = board.size();
        char curr_val = '.';
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                curr_val = board[i][j];
                if(curr_val == '.') continue;
                if(curr_val >='1' && curr_val <= '9'){
                    box_key = i/3 * 3 + j/3;
                    if(!index_row_map[i].insert(curr_val).second || 
                        !index_col_map[j].insert(curr_val).second ||
                        !index_sub_box[box_key].insert(curr_val).second) return false;
                }
                else return false;
            }
        }

        return true;
    }
};
