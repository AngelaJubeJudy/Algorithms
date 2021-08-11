class LongestCommonPrefix {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 处理边界
        if(strs.size() == 0) return "";

        string ans = strs[0];
        for(int i = 1; i < strs.size(); i++){
            ans = commonPrefix(ans, strs[i]);
            if(!ans.size()) break;
        }
        return ans;
    }
    
    string commonPrefix(const string& str1, const string& str2) {
        int prefixLen = min(str1.size(), str2.size());
        int cursor = 0;
        while(cursor < prefixLen && str1[cursor] == str2[cursor]) ++cursor;
        return str1.substr(0, cursor);
    }
};