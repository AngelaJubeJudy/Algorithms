class FindContentChildren {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 排序胃口
        sort(g.begin(), g.end());
        // 排序饼干
        sort(s.begin(), s.end());

        int j = 0; 
        int ans = 0;
        for(int i = 0; i < g.size(); i++){
            while(j < s.size() && s[j] < g[i]) j++;
            if(j < s.size()) j++, ans++;
        }
        return ans;
    }
};