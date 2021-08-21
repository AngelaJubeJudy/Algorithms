class SolveSudoku {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int initial = 1022;  // 二进制：1111111110
        for(int i = 0; i < 9; i++){
            row[i] = initial;
            col[i] = initial;
            box[i] = initial;
        }

        // memset(row, true, sizeof(row));
        // memset(col, true, sizeof(col));
        // memset(box, true, sizeof(box));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char ch = board[i][j];
                if(ch != '.'){
                    int digit  = board[i][j] - '0';
                    int boxId = i / 3 * 3 + j / 3;
                    row[i] = row[i] ^ (1 << digit);
                    col[j] = col[j] ^ (1 << digit);
                    box[boxId] = box[boxId] ^ (1 << digit);
                    // row[i][digit] = false;
                    // col[j][digit] = false;
                    // box[i / 3 * 3 + j / 3][digit] = false;
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
        int boxId = x / 3 * 3 + y / 3;

        int availability = row[x] & col[y] & box[boxId];
        for(int digit = 1; digit <= 9; digit++){
            // 判断可用性
            // if(row[x][digit] && col[y][digit] && box[x / 3 * 3 + y / 3][digit]){
            //     row[x][digit] = col[y][digit] = box[x / 3 * 3 + y / 3][digit] = false;
            //     char ch = '0' + digit;
            //     board[x][y] = ch;
                
            //     if(dfs(board)) return true;
            //     //还原现场
            //     board[x][y] = '.';
            //     row[x][digit] = col[y][digit] = box[x / 3 * 3 + y / 3][digit] = true;
            // }
            if((availability >> digit & 1) == 1){
                row[x] ^= 1 << digit;
                col[y] ^= 1 << digit;
                box[boxId] ^= 1 << digit;
                char ch = '0' + digit;
                board[x][y] = ch;
                if(dfs(board)) return true;

                board[x][y] = '.';
                row[x] ^= 1 << digit;
                col[y] ^= 1 << digit;
                box[boxId] ^= 1 << digit;
            }
        }
        return false;
    }

    pair<int, int> getFirstEmptyPosition(vector<vector<char>>& board) {
        int ansCount = 10;
        pair<int, int> ans = make_pair(-1,-1);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                int boxId = i/3*3 + j/3;
                char ch = board[i][j];
                if(ch == '.'){
                    int cnt = hammingWeight(row[i] & col[j] & box[boxId]);
                    if(cnt < ansCount){
                        ansCount = cnt;
                        ans = make_pair(i, j);
                    }
                }
            }
        }
        return ans;
    }
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n > 0){
            count++;
            n -= n & -n;
        }
        return count;
    }

private:
    // 判断合法性
    // bool row[9][10];  // 在每一行只能出现一次
    // bool col[9][10];  // 在每一列只能出现一次
    // bool box[9][10];  // 在每一个以粗实线分隔的 3x3 宫内只能出现一次

    int row[9];
    int col[9];
    int box[9];
};