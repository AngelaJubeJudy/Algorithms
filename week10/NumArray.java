class NumArray {

    public NumArray(int[] nums) {
        n = nums.length;
        a = new int[n+1];  // 使下标从1开始
        c = new int[n+1];

        for(int i = 1; i <=n; i++){
            a[i] = nums[i - 1];
            add(i, a[i]);
        }

    }
    
    public void add(int x, int delta) {
        for(; x <= n; x +=lowbit(x)) c[x] += delta;
    }

    public int query(int x){
        int ans = 0;
        for(; x>0; x -= lowbit(x)) ans +=c[x];
        return ans;
    }

    public int lowbit(int x){
        return x & (-x);
    }
    
    public void update(int index, int val) {
        // 单点修改
        index++;
        int delta = val - a[index];
        add(index, delta);
        a[index] = val;
    }
    
    public int sumRange(int left, int right) {
        // 区间和
        left++;
        right++;
        return query(right) - query(left - 1);
    }

    int[] a;
    int[] c;
    int n;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
