class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9); 
        vector<unordered_set<char>> cols(9); 
        vector<unordered_set<char>> boxs(9); 

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                char val = board[i][j]; 

                if(val == '.') {
                    continue; 
                } else {
                    if(rows[i].contains(val) || cols[j].contains(val)) {
                        return false; 
                    }; 
                    rows[i].insert(val);
                    cols[j].insert(val); 
                }
                
                int box = (i / 3) * 3 + (j / 3);
                if(boxs[box].contains(val)) {
                    return false; 
                } else {
                    boxs[box].insert(val); 
                }
            }
        }; 

        return true; 
        
    }
};
