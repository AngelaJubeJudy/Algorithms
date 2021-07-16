class SolveNQueens {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        used = vector<bool>(n ,false);
        find(0);

        vector<vector<string>> result;
        for(vector<int>& per: ans){
            vector<string> res;
            for (int row=0; row < n; row++){
                string s(n, '.');
                int col = per[row];
                s[col] = 'Q';
                res.push_back(s);
            }
            result.push_back(res);
        }
        return result;
    }

    // 全排列
    void find(int i){
        if(i == n){
            ans.push_back(s);
            return;
        }
        for(int j=0; j<n; j++){
            if(!used[j] && !usedLeftDown[i + j] && !usedRightUp[i - j]){
                used[j] = true;
                usedLeftDown[i+j] = true;
                usedRightUp[i-j] = true;
                s.push_back(j);
                find(i+1);
                s.pop_back();
                usedLeftDown[i+j] = false;
                usedRightUp[i-j] = false;
                used[j] = false;
            }

        }
    }

private:
    vector<vector<int>> ans;
    vector<int> s;
    vector<bool> used;
    int n;
    unordered_map<int, bool> usedLeftDown; // "/"
    unordered_map<int, bool> usedRightUp; // "\"
};