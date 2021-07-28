class MaxCoins {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> ans(n+2, vector<int>(n+2, 0));

        for(int len = 1; len <= n; len++){
            for(int l = 1; l <= n-len+1; l++){  // 左端点
                int r = l + len - 1;  // 右端点
                for(int p = l; p <= r; p++){
                    ans[l][r] = max(ans[l][r], ans[l][p-1] + ans[p+1][r] + nums[l-1]*nums[p]*nums[r+1]);
                }
            }
        }
        return ans[1][n];
    }
};