class GenerateParenthesis {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        vector<string> ans;
        // 第一段：k对括号
        // 剩余段：（n-k）对括号；可为空
        for(int k = 1; k <= n; k++){
            vector<string> result1 = generateParenthesis(k - 1);
            vector<string> result2 = generateParenthesis(n - k);
            for(string& sa: result1){
                for(string& sb: result2){
                    ans.push_back("("+sa+")"+sb);
                }
            }
        }
        return ans;
    }
};