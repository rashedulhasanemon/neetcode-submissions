class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int,std::unordered_set<char>> index_row_map;
        std::unordered_map<int,std::unordered_set<char>> index_col_map;
        std::unordered_map<int, std::unordered_set<char>> index_sub_box;
        int box_key = 0;
        size_t size = board.size();
        char curr_val = '.';
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                curr_val = board[i][j];
                if(curr_val == '.') continue;
                if(curr_val >='1' && curr_val <= '9'){
                    if(index_row_map[i].insert(curr_val).second == false) return false;
                    if(index_col_map[j].insert(curr_val).second == false) return false;
                    box_key = i/3 * 31 + j/3;
                    if(index_sub_box[box_key].insert(curr_val).second == false) return false;
                }
                else return false;
            }
        }

        return true;
    }
};
