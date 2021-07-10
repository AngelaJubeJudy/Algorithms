class LongestIncreasingPath {
    public int longestIncreasingPath(int[][] matrix) {
        // 有向，无环

        // 初始化
        m = matrix.length;
        n = matrix[0].length;
        ans = new int[m][n];
        int result = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) ans[i][j] = -1;

        // 找最长路径
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                result = Math.max(result, howFar(matrix, i, j));
        return result;
    }

    int howFar(int[][] matrix, int x, int y){
        if(ans[x][y] != -1) return ans[x][y];
        // 默认值
        ans[x][y] = 1;

        for(int i=0; i<4; i++){
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            // 边界
            if(nextX < 0 || nextY < 0 || nextX >= m || nextY >= n) continue;

            if(matrix[nextX][nextY] > matrix[x][y]){
                ans[x][y] = Math.max(ans[x][y], howFar(matrix, nextX, nextY) + 1);
            }
        }
        return ans[x][y];
    }

    private int m;
    private int n;
    private int[] dx = new int[]{-1,0,0,1};
    private int[] dy = new int[]{0,-1,1,0};
    int[][] ans;
}