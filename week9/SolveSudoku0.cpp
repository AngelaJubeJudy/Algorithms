class SolveSudoku0 {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }

    bool dfs(vector<vector<char>>& board) {
        pair<int, int> location = getFirstEmptyPosition(board);
        int x = location.first;
        int y = location.second;
        if(x == -1) return true;
        for(int digit = 1; digit <= 9; digit++){
            char ch = '0' + digit;
            board[x][y] = ch;
            if(isValidSudoku(board) && dfs(board)) return true;
            board[x][y] = '.';
        }
        return false;
    }

    pair<int, int> getFirstEmptyPosition(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char ch = board[i][j];
                if(ch == '.') return make_pair(i, j);
            }
        }
        return make_pair(-1, -1);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // 判断合法性
        // 存储各位置数字1~9的出现次数
        unordered_set<char> row[9];  // 在每一行只能出现一次
        unordered_set<char> col[9];  // 在每一列只能出现一次
        unordered_set<char> box[9];  // 在每一个以粗实线分隔的 3x3 宫内只能出现一次

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char ch = board[i][j];
                if(ch == '.') continue;

                // 计算在哪个box
                int boxId = i / 3 * 3 + j / 3;

                // 剪枝
                if(row[i].find(ch) != row[i].end()) return false;
                row[i].insert(ch);
                if(col[j].find(ch) != col[j].end()) return false;
                col[j].insert(ch);
                if(box[boxId].find(ch) != box[boxId].end()) return false;
                box[boxId].insert(ch);
            }
        }
        return true;
    }
};