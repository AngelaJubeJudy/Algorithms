class ValidPalindrome {
public:
    bool validPalindrome(string s) {
        return checkPalindrome(s, 0, s.length() - 1, true);
    }

    bool checkPalindrome(const string& s, int l, int r, bool canDel){
        while(l < r){
            if(s[l] == s[r]){
                l++;
                r--;
            }else{
                if(canDel){
                    return checkPalindrome(s, l+1, r, false) || checkPalindrome(s, l, r-1, false);
                }else return false;
            }
        }
        return true;
    }
};