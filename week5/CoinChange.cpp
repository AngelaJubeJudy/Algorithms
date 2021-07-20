class CoinChange {
public:
    int coinChange(vector<int>& coins, int amount) {
        int INF = (int)1e9;
        vector<int> ans(amount + 1);
        ans[0] = 0;
        sort(coins.begin(), coins.end());
        
        for(int i = 1; i <= amount; i++){
            ans[i] = INF;
            for(int now = 0; now < coins.size(); now++){
                if(i - coins[now] >= 0){  // 下标有效
                    ans[i] = min(ans[i], 1 + ans[i - coins[now]]);
                }
            }
        }

        if(ans[amount] >= INF) ans[amount] = -1;
        return ans[amount];
    }
};