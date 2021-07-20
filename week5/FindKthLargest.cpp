class FindKthLargest {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // method 1: 暴力, O(n·logn)
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() - k];

        // method 2: 快排, O(n)
        return quickSort(nums, nums.size() - k, 0, nums.size() - 1);

        // method 3: 堆排序, O(k·logn)
    }

    int quickSort(vector<int>& nums, int k, int l, int r){
        // 边界
        if(l == r) return nums[l];

        // 分区快排
        int pivot = partition(l, r, nums);
        if(pivot >= k) return quickSort(nums, k, l, pivot);
        else return quickSort(nums, k, pivot + 1, r);
    }

    int partition(int left, int right, vector<int>& nums){
        int pivot = nums[left + rand() % (right - left + 1)];
        while(left <= right){
            while(nums[left] < pivot) left++;
            while(nums[right] > pivot) right--;
            if(left <= right){
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
                left++;
                right--;
            }
        }
        return right;
    }
};