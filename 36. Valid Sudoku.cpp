 bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9),cols(9),blocks(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.')continue;
                int val = board[i][j] - '0';
                if(rows[i].count(val)||cols[j].count(val)||blocks[(i/3)*3+j/3].count(val))return false;
                rows[i].insert(val);
                cols[j].insert(val);
                blocks[(i/3)*3+j/3].insert(val);
            }
        }
        return true;
    }
