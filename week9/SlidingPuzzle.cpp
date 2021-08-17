class SlidingPuzzle {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int target = 123450;
        vector<int> list;
        // 初始化
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                list.push_back(board[i][j]);
            }
        }
        int start = zip(list);
        q.push(start);
        dist[start] = 0;

        while(!q.empty()){
            int now = q.front();
            q.pop();
            auto a = unzip(now);
            int pos = getZeroIndex(a);

            // 交换位置
            if(pos%3 > 0) insert(pos, pos - 1, a, now);  // 向左
            if(pos%3 < 2) insert(pos, pos + 1, a, now);  // 向右
            if(pos >= 3) insert(pos, pos - 3, a, now);  // 向上
            if(pos < 3) insert(pos, pos + 3, a, now);  // 向下
            if(dist.find(target) != dist.end()) return dist[target];
        }

        return -1;
    }

    void insert(int pos, int newPos, vector<int>& a, int now){
        swap(a[pos], a[newPos]);
        int next = zip(a);
        if(dist.find(next) == dist.end() || dist[next] > dist[now] + 1){
            dist[next] = dist[now] + 1;
            q.push(next);
        }

        //还原
        swap(a[newPos], a[pos]);
    }

    // 定位空位
    int getZeroIndex(vector<int>& a){
        for(int i = 0; i < 6; i++){
            if(a[i] == 0) return i;
        }
        return -1;
    }

    // 2*3 board -> 1*6 string
    int zip(vector<int>& a){
        int res = 0;
        for(int i = 0; i < 6; i++){
            res = res*10 + a[i];
        }
        return res;
    }

    // 1*6 string -> 2*3 board 
    vector<int> unzip(int state){
        vector<int> a(6, 0);
        for(int i = 5; i >= 0; i--){
            a[i] = state%10;
            state /= 10;
        }
        return a;
    }

private:
    queue<int> q;
    unordered_map<int, int> dist;
};