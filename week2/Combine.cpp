class Combine {
    public List<List<Integer>> combine(int n, int k) {
        ans = new ArrayList<List<Integer>>();
        set = new ArrayList<Integer>();
        this.n = n;
        this.k = k;
        finSubset(1);
        return ans;
    }

    private void finSubset(int index){
        // 剪枝：选超了，或者，全选剩余的也不够
        if(set.size() > k || set.size()+n-index+1 < k) return; 

        // 边界
        if(index == n + 1){
            if(set.size() == k) ans.add(new ArrayList<Integer>(set));
            return;
        }

        // 选择1：不选
        finSubset(index + 1);
        // 选择2：选
        set.add(index);
        finSubset(index + 1);
        // 还原现场
        set.remove(set.size() - 1);
    }

    private List<List<Integer>> ans;
    private List<Integer> set;
    private int n;
    private int k;
}