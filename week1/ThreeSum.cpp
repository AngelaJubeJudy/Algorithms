class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 先排序，方便去重
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            // 去重
            if(i > 0 && nums[i] == nums[i-1]) continue;
            //利用两束之和求解值为-nums[i]的解个数
            auto ans = twoSum(nums, i+1, -nums[i]);
            for(auto answer: ans){
                result.push_back({nums[i], answer[0], answer[i]});
            }
        }

        return result;
    }

private:
    vector<vector<int>> twoSum(vector<int>& numbers, int start, int target) {
        vector<vector<int>> result;
        int j = numbers.size() - 1;
        for (int i = 0; i < numbers.size(); i++) {
            if(i > start && numbers[i] == numbers[i-1]) continue;
            while (i < j && numbers[i] + numbers[j] > target) j--;
            if (i < j && numbers[i] + numbers[j] == target) {
                result.push_back({numbers[i], numbers[j]});
            }
        }
        return result;
    }
};