class FlowerMinDays {
    public int minDays(int[] bloomDay, int m, int k) {
        // 做m束花，每束花用的是连续k朵 => 取m段长为k的子段
        // T作为时间分界点，之后的天数里都可以制作花束
        int l = 0;
        int MAX = 1000000001;
        int r = 1000000001;  // 上限：无解
        while(l < r){
            int mid = (l+r) >> 1;
            if(isValidOnDay(bloomDay, m, k, mid)) r = mid;
            else l = mid +1;
        }

        if(r == MAX) r = -1;
        return r;
    }
    
    private boolean isValidOnDay(int[] bloomDay, int m, int k, int T){
        int consecutive = 0;
        int bouquet = 0;
        for(int i=0; i < bloomDay.length; i++){
            // 单调性0/1函数：关于条件单调
            if(bloomDay[i] <= T){  // 已开
                consecutive++;
                if(consecutive == k){
                    bouquet++;  // k朵一束花
                    consecutive = 0;
                }
            }else consecutive = 0;  // 还没开
        }
        return bouquet >= m;
    }
}