class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<int> index_row_map(9,0);
        std::vector<int> index_col_map(9,0);
        std::vector<int> index_sub_box(9,0);

        int sub_box = 0;
        size_t size = board.size();
        char curr_val = '.';

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                curr_val = board[i][j];
                if(curr_val == '.') continue;
                int val = int(curr_val) - '1';
                if((index_row_map[i] >> val) & 0x1) 
                    return false;
                if((index_col_map[j] >> val) & 0x1) 
                    return false;
                sub_box = (i / 3) * 3 + j / 3;
                if((index_sub_box[sub_box] >> val) & 0x1) 
                    return false;
            
                index_row_map[i] |= (1 << val);
                index_col_map[j] |= (1 << val);   
                index_sub_box[sub_box] |= (1 << val);
            }
        }

        return true;
    }
};
