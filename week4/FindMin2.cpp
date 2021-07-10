class FindMin2 {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() -1;

        while(start < end){
            int mid = (end+start) >> 1;
            if(mid == 0 && nums[mid] < nums[end]) break;
            if (nums[mid] <= nums[end]){
                if(nums[mid] == nums[end]) end--;
                else end = mid;
            }
            else start = mid + 1;
        }
        return nums[start];
    }
};