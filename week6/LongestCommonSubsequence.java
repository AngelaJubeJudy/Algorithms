class LongestCommonSubsequence {
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();
        text1 = " " + text1;
        text2 = " " + text2;

        int[][] ans = new int[n+1][m+1];

        for(int i = 0; i < n; i++) ans[i][0] = 0;
        for(int j = 0; j < m; j++) ans[0][j] = 0;

        for(int i = 1; i <=n; i++){
            for(int j = 1; j <=m; j++){
                if(text1.charAt(i) == text2.charAt(j)) ans[i][j] = ans[i-1][j-1] + 1;
                else ans[i][j] = Math.max(ans[i-1][j], ans[i][j-1]);
            }
        }

        return ans[n][m];
    }
}