class CountBits {
public:
    vector<int> countBits(int n) {
        // 方法一
        // vector<int> ans;
        // for(int i = 0; i <= n; i++){
        //     ans.push_back(hammingWeight(i));
        // }

        // 方法二
        vector<int> ans(n+1);
        ans[0] = 0;
        for(int i = 1; i <= n; i++){
            ans[i] = ans[i & (i - 1)] + 1;
        }

        return ans;
    }

    // int hammingWeight(uint32_t n) {
    //     int count = 0;
    //     while(n > 0){
    //         count++;
    //         n -= n & -n;
    //     }
    //     return count;
    // }
};