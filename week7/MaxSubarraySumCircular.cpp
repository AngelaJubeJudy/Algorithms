class MaxSubarraySumCircular {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int> sum(n+1, 0);

        // Step 1：计算前缀和
        for(int i = 1; i <= n; i++){
            sum[i] = sum[i - 1] + nums[i];
        }

        // Step 2：最大字段和
        int ans = -1000000000;
        int tmp = sum[0];
        for(int i = 1; i <= n; i++){
            tmp = min(tmp, sum[i-1]);
            ans = max(ans, sum[i] - tmp);
        }

        // Step 3：最小字段和
        int ansMin = 1000000000;
        tmp = sum[0];
        for(int i = 1; i < n; i++){
            tmp = max(tmp, sum[i-1]);
            ansMin = min(ansMin, sum[i] - tmp);
        }

        // Step 4：最小字段和不能全取
        tmp = sum[1];
        for(int i = 2; i < n; i++){
            tmp = max(tmp, sum[i]);
        }
        if(n > 1) ansMin = min(ansMin, sum[n] - tmp);
        ans = max(ans, sum[n] - ansMin);

        return ans;
    }
};