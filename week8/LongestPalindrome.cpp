class LongestPalindrome {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";

        // 通过中点枚举
        int n = s.length();
        int ansLen = 0;
        int ansStart = 0;
        s = ' ' + s;

        // 长度为奇数：中心一个字符
        for(int center = 1; center <= n; center++){
            int l = center - 1;
            int r = center + 1;
            while(l > 0 && r <= n && s[l] == s[r]){
                l--; r++;
            }
            if(r - l - 1 > ansLen){
                ansLen = r - l - 1;
                ansStart = l + 1;
            }
        }
        // 中心为一个空
        for(int center = 1; center <= n; center++){
            int l = center;
            int r = center + 1;
            while(l > 0 && r <= n && s[l] == s[r]){
                l--; r++;
            }
            if(r - l - 1 > ansLen){
                ansLen = r - l - 1;
                ansStart = l + 1;
            }
        }
        return s.substr(ansStart, ansLen);
    }
};