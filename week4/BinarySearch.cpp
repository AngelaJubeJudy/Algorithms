class BinarySearch {
public:
    int search(vector<int>& nums, int target) {
        return find(nums, 0, nums.size(), target);
    }

    int find(vector<int>& nums, int start, int end, int target){
        
        while(start < end){
            int mid = (end+start) >> 1;
            if(nums[mid] == target) return mid;
            else if (nums[mid] < target) start = mid + 1;
            else end = mid;
        }
        return -1;
    }
};
