class UniquePathsWithObstacles {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length;
        int m = obstacleGrid[0].length;
        int[][] ans = new int[n][m];

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (obstacleGrid[i][j] == 1) ans[i][j] = 0;  // 障碍
                else if (i == 0 && j == 0) ans[i][j] = 1;  // 初始值
                else if (i == 0) ans[i][j] = ans[i][j-1];  // 向下
                else if (j == 0) ans[i][j] = ans[i-1][j];  // 向右
                else ans[i][j] = ans[i-1][j] + ans[i][j-1];  // 转移方程
            }
        }

        return ans[n-1][m-1];
    }
}