class MaxCoins {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // 方法一：动态规划
        // vector<vector<int>> ans(n+2, vector<int>(n+2, 0));
        // for(int len = 1; len <= n; len++){  // 循环1~n的气球
        //     for(int l = 1; l <= n-len+1; l++){  // 左端点
        //         int r = l + len - 1;  // 右端点
        //         for(int p = l; p <= r; p++){
        //             ans[l][r] = max(ans[l][r], ans[l][p-1] + ans[p+1][r] + nums[l-1]*nums[p]*nums[r+1]);
        //         }
        //     }
        // }
        // return ans[1][n];

        // 方法二：DFS+记忆化
        f = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        return dfs(1, n, nums);
    }

    int dfs(int l, int r, vector<int>& nums){
        // 边界处理
        if(l > r) return 0;

        // 记忆化剪枝
        if(f[l][r] >= 0) return f[l][r];

        // 主体思路
        f[l][r] = 0;
        for(int p = l; p <= r; p++){
            f[l][r] = max(f[l][r], dfs(l, p-1, nums) + dfs(p+1, r, nums) + nums[l-1]*nums[p]*nums[r+1]);
        }
        return f[l][r];
    }
private:
    vector<vector<int>> f;
};
