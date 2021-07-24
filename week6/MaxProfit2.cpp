class MaxProfit2 {
public:
    int maxProfit(vector<int>& prices) {
        return calc(prices, 0);
    }

    int calc(vector<int>& prices, int fee){
        // 初值
        int n = prices.size();
        vector<vector<int>> f(n+1, vector<int>(2, -10000000));
        prices.insert(prices.begin(), 0);
        f[0][0] = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j <= 1; j++){
                // Buy
                if(j == 0) f[i+1][1] = max(f[i+1][1], f[i][j]-prices[i+1]-fee);
                
                // Sell
                if(j == 1) f[i+1][0] = max(f[i+1][0], f[i][j]+prices[i+1]);
                
                // Rest
                f[i+1][j] = max(f[i+1][j], f[i][j]);
            }
        }
        return f[n][0];
    }
};