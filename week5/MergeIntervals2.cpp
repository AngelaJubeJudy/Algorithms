class MergeIntervals2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 双关键字排序：2个长为2的数组的比较
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        // “差分”
        // +1事件=正在覆盖，-1事件=判断已有事件能否延续（count=0时停止）
        // 非零->零：结束；零->非零，开始覆盖
        vector<vector<int>> ans;
        vector<pair<int, int>> events;
        
        // step 1: 2n个事件
        for(vector<int>& interval: intervals){
            events.push_back(make_pair(interval[0], 1));
            events.push_back(make_pair(interval[1]+1, -1));

        }

        // step 2: 判断覆盖过程
        sort(events.begin(), events.end());
        int count = 0;
        int left = 0;
        for(pair<int, int>& event: events){
            // 开始覆盖
            if(count == 0) left = event.first;
            count += event.second;
            // 结束覆盖
            if(count == 0) ans.push_back({left, event.first - 1});
        }
        return ans;
    }
};