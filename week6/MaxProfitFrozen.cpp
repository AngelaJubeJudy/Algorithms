class MaxProfitFrozen {
public:
    int maxProfit(vector<int>& prices) {
        return calc(prices, 0);
    }

    int calc(vector<int>& prices, int fee){
        // 初值
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        vector<vector<vector<int>>> f(n+1, vector<vector<int>>(2, vector<int>(2, -10000000)));
        f[0][0][0] = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j <= 1; j++){
                for(int l = 0; l <= 1; l++){
                    // Buy
                    if(j == 0 &&l == 0)
                        f[i+1][1][0] = max(f[i+1][1][0], f[i][j][l]-prices[i+1]-fee);
                    // Sell
                    if(j == 1 && l == 0)
                        f[i+1][0][1] = max(f[i+1][0][1], f[i][j][l]+prices[i+1]);
                    
                    // Rest
                    f[i+1][j][0] = max(f[i+1][j][0], f[i][j][l]);
                }
            }
        }

        int ans = 0;
        for(int l = 0; l <= 1; l++){
            ans = max(ans, f[n][0][l]);
        }
        return ans;
    }
};