class LetterCombinations {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};

        phone['2'] = "abc";
        phone['3'] = "def";
        phone['4'] = "ghi";
        phone['5'] = "jkl";
        phone['6'] = "mno";
        phone['7'] = "pqrs";
        phone['8'] = "tuv";
        phone['9'] = "wxyz";
        phone['0'] = "abc";

        // 树的遍历
        dfs(digits, 0);
        return result;
    }

private:
    void dfs(string& digits, int index){
        if(index == digits.length()){
            result.push_back(ans);
            return;
        }

        for(char ch: phone[digits[index]]){
            ans.push_back(ch);
            dfs(digits, index+1);
            ans.pop_back();
        }
    }
    unordered_map<char, string> phone;
    string ans;
    vector<string> result;
};