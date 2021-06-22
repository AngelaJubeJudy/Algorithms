class NumberOfSubarrays {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        // 前缀和
        int capacity = nums.size();
        vector<int> sum(capacity + 1, 0);
        nums.insert(nums.begin(), 0);
        for(int i = 1; i <= capacity; i++){
            sum[i] = sum[i-1] + nums[i] % 2;
        }

        // 前缀和计数
        vector<int> count(capacity + 1, 0);
        for (int i = 0; i <= capacity; i++) count[sum[i]]++;

        int result = 0;
        for (int i = 0; i <= capacity; i++){
            if(sum[i] - k >= 0) result += count[sum[i] - k];
        }
        return result;

    }
};