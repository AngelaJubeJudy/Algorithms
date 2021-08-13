class SolveSudoku2 {
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, true, sizeof(row));
        memset(col, true, sizeof(col));
        memset(box, true, sizeof(box));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char ch = board[i][j];
                if(ch != '.'){
                    int digit  = board[i][j] - '0';
                    row[i][digit] = false;
                    col[j][digit] = false;
                    box[i / 3 * 3 + j / 3][digit] = false;
                }
            }
        }
        dfs(board);
    }

    bool dfs(vector<vector<char>>& board) {
        pair<int, int> location = getFirstEmptyPosition(board);
        int x = location.first;
        int y = location.second;
        if(x == -1) return true;
        for(int digit = 1; digit <= 9; digit++){
            int bid = x / 3 * 3 + y / 3;
            // 判断可用性
            if(row[x][digit] && col[y][digit] && box[bid][digit]){
                row[x][digit] = col[y][digit] = box[bid][digit] = false;
                char ch = '0' + digit;
                board[x][y] = ch;

                if(dfs(board)) return true;
                //还原现场
                board[x][y] = '.';
                row[x][digit] = col[y][digit] = box[x / 3 * 3 + y / 3][digit] = true;
            }
        }
        return false;
    }

    pair<int, int> getFirstEmptyPosition(vector<vector<char>>& board) {
        int ansCount = 10;
        pair<int, int> ans = make_pair(-1, -1);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char ch = board[i][j];
                if(ch == '.'){
                    int count = 0; 
                    int bid = i / 3 * 3 + j / 3;
                    for(int digit = 1; digit <= 9; digit++){
                        if(row[i][digit] && col[j][digit] && box[bid][digit]){
                            count++;
                        }
                    }
                    if(count < ansCount){
                        ansCount = count;
                        ans = make_pair(i, j);
                    }
                }
            }
        }
        return ans;
    }

private:
    // 判断合法性
    bool row[9][10];  // 在每一行只能出现一次
    bool col[9][10];  // 在每一列只能出现一次
    bool box[9][10];  // 在每一个以粗实线分隔的 3x3 宫内只能出现一次
};