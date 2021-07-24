class MaxProfit3 {
public:
    int maxProfit(vector<int>& prices) {
        return calc(prices, 2, 0);
    }

    int calc(vector<int>& prices, int c, int fee){
        // 初值
        int n = prices.size();
        vector<vector<vector<int>>> f(n+1, vector<vector<int>>(2, vector<int>(c+1, -10000000)));
        prices.insert(prices.begin(), 0);
        f[0][0][0] = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j <= 1; j++){
                for(int k = 0; k <= c; k++){
                    // Buy
                    if(j == 0 && k < c) f[i+1][1][k+1] = max(f[i+1][1][k+1], f[i][j][k]-prices[i+1]-fee);
                    
                    // Sell
                    if(j == 1) f[i+1][0][k] = max(f[i+1][0][k], f[i][j][k]+prices[i+1]);
                    
                    // Rest
                    f[i+1][j][k] = max(f[i+1][j][k], f[i][j][k]);
                }
            }
        }

        int ans = 0;
        for(int k = 0; k <= c; k++){
            ans = max(ans, f[n][0][k]);
        }
        return ans;
    }
};
