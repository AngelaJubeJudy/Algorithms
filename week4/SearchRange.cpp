class SearchRange {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        // 开始位置：第一个 >= target 的
        int start = 0;
        int end = nums.size();
        while(start < end){
            int mid = (end+start) >> 1;
            if(nums[mid] >= target) end = mid;
            else start = mid + 1;
        }
        ans.push_back(end);

        // 结束位置：最后一个 <= target 的
        start = -1;
        end = nums.size() - 1;
        while(start < end){
            int mid = (end+start+1) >> 1;
            if(nums[mid] <= target) start = mid;
            else end = mid - 1;
        }
        ans.push_back(end);

        if(ans[0] > ans[1]) ans = {-1, -1};
        return ans;
    }
};
