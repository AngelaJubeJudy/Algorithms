class FindPeakElement {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int leftmid = (l+r)/2;
            int rightmid = leftmid + 1;
            if(nums[leftmid] < nums[rightmid]) l = leftmid + 1;
            else r = rightmid-1;
        }
        return l;
    }
};