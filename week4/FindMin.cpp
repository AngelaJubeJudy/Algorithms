class FindMin {
public:
    int findMin(vector<int>& nums) {
        // 分段性质 => 二分条件：左段 >nums[r]，右段 <= nums[l]
        int start = 0;
        int end = nums.size() -1;

        while(start < end){
            int mid = (end+start) >> 1;
            if (nums[mid] <= nums[end]) end = mid;
            else start = mid + 1;
        }
        return nums[start];
    }
};
