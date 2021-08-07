class StrStr {
    public int strStr(String s, String t) {
        if(t.length() == 0) return 0;
        int n = s.length();
        int m = t.length();
        s = " " + s;
        t = " " + t;
        int p = (int)1e9 + 7;  // 大质数
        
        long tHash = 0;
        for(int i = 1; i <= m; i++){
            tHash = (tHash*131 + (t.charAt(i) - 'a' + 1)) % p;  // 字母最小映射为1
        }

        // 预处理次幂
        long[] p131 = new long[n+1];
        p131[0] = 1;

        long[] sHash = new long[n+1];
        sHash[0] = 0;
        for(int i = 1; i <= n; i++){
            sHash[i] = (sHash[i-1]*131 + (s.charAt(i) - 'a' + 1)) % p;
            p131[i] = p131[i-1]*131 % p;
        }

        // 滑动窗
        for(int i = m; i <= n; i++){
            if(calcHash(sHash, p131, p, i-m+1, i) == tHash && s.substring(i-m+1, i+1).equals(t.substring(1))) return i-m;
        }

        return -1;
    }
    private long calcHash(long[] H, long[] p131, int p, int l, int r){
        return (H[r] - H[l-1]*p131[r-l+1] % p + p) % p;
    }
}