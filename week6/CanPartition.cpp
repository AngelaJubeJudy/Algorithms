class CanPartition {
public:
    bool canPartition(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum % 2 == 1) return false;
        sum /= 2;
        vector<bool> ans(sum+1, false);

        ans[0] = true;
        for(int i = 1; i < n; i++){
            for(int j = sum; j >= nums[i]; j--){
                ans[j] = ans[j] | ans[j - nums[i]];
            }
        }
        return ans[sum];
    }
};