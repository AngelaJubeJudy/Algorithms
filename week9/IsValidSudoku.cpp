class IsValidSudoku {
public:
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
