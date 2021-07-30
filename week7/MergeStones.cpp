class MergeStones {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        vector<int> sum(n, 0);
        sum[0] = stones[0];
        // 前缀和
        for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + stones[i];

        int INF = 1000000000;
        vector<vector<vector<int>>> ans(n+1, vector<vector<int>>(n+1, vector<int>(k+1, INF)));
        for(int i = 0; i < n; i++) ans[i][i][1] = 0; 

        for(int len = 2; len <= n; len++){  // 区间动态规划：循环每堆石头
            for(int l = 0; l <= n - len; l++){  
                int r = l + len - 1;

                // 分一堆 + 子问题分(i-1)堆
                for(int j = 2; j <= k; j++){  // 循环状态
                    for(int p = l; p < r; p++){  // 循环决策
                        ans[l][r][j] = min(ans[l][r][j], ans[l][p][1] + ans[p + 1][r][j - 1]);
                    }
                }

                // k堆合并为一堆
                int tmp = 0;
                if(l) tmp = sum[l-1];
                ans[l][r][1] = min(ans[l][r][1], ans[l][r][k] + sum[r] - tmp);
            }
        }

        if(ans[0][n - 1][1] >= INF) return -1;
        return ans[0][n - 1][1];
    }
};