class MergeIntervals1 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 双关键字排序：2个长为2的数组的比较
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        // 覆盖次数的统计：>=1的重叠
        // 最远端的更新
        int farthest = -1;
        vector<vector<int>> ans;
        int currLeft = -1;

        for(vector<int>&interval: intervals){
            int start = interval[0];
            int end = interval[1];

            // 可以延续
            if(start <= farthest) farthest = max(farthest, end);
            // 另起新一段区间
            else{
                if(farthest >= 0) ans.push_back({currLeft, farthest});
                currLeft = start;
                farthest = end;
            }
        }

        if(farthest >= 0) ans.push_back({currLeft, farthest});
        return ans;
    }
};