class Jump {
public:
    int jump(vector<int>& nums) {
        int now = 0;
        int ans = 0;

        while(now < nums.size() - 1){
            if(nums[now] == 0) return -1;

            int right = now + nums[now];
            if(right >= nums.size() - 1) return ans + 1;

            int next = now + 1;
            for(int i=now + 2; i <= right; i++){
                int next_pos = i + nums[i];
                if(next_pos > next + nums[next]) next = i;
            }

            now = next;
            ans++;
        }
        return ans;
    }
};