class SplitArray {
    public int splitArray(int[] nums, int m) {
        // 二分
        int l = 0;
        int r = 0;
        for(int i=0; i < nums.length; i++){
            l = Math.max(l, nums[i]);
            r += nums[i];
        } 

        while(l < r){
            int mid = (l + r) / 2;
            // 判定：分组，每组的和不超过T；找第一个true
            if(isValid(nums, m, mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
    
    private boolean isValid(int[] nums, int m, int T){
        int count = 1;
        int arraySum = 0;
        for(int i=0; i < nums.length; i++){
            // 单调性0/1函数：关于条件单调
            if(arraySum + nums[i] <= T) arraySum+=nums[i];
            else{
                count++;
                arraySum = nums[i];  // 新开一组放导致超限的元素
            }
        }
        return count <= m;
    }
}
