class Subsets {
    public List<List<Integer>> subsets(int[] nums) {
        ans = new ArrayList<List<Integer>>();
        set = new ArrayList<Integer>();
        finSubset(nums, 0);
        return ans;
    }

    private void finSubset(int[] nums, int index){
        // 边界
        if(index == nums.length){
            ans.add(new ArrayList<Integer>(set));
            return;
        }

        // 选择1：不选
        finSubset(nums, index + 1);
        // 选择2：选
        set.add(nums[index]);
        finSubset(nums, index + 1);
        set.remove(set.size() - 1);
    }

    private List<List<Integer>> ans;
    private List<Integer> set;
}