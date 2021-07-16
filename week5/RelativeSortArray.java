class RelativeSortArray {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int n = 0;
        int[] ans = new int[arr1.length];

        // 计数排序
        int[] count = new int[1001];
        for(int i=0; i < arr1.length; i++){
            count[arr1[i]]++;
        }

        // 按照arr2的顺序排序
        for(int i=0; i < arr2.length; i++){
            while(count[arr2[i]] > 0){
                count[arr2[i]]--;
                ans[n] = arr2[i];
                n++;
            }
        }
        // arr1计数排序
        for(int val = 0; val <= 1000; val++){
            while(count[val] > 0){
                count[val]--;
                ans[n] = val;
                n++;
            }
        }
        return ans;
    }
}