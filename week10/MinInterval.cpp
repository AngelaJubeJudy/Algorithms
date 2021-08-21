class MinInterval {
public:
    struct Event{
        int type;
        int pos;
        int length;  // 按事件分类：询问的index，区间的length
    };
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // 事件分类（闭区间）：2n + m
        // 发生：产生区间长度
        // 询问：答案为 min（区间长度）
        // 消失：删除维护的区间长度
        // 排序 2n + m 个事件，批处理

        vector<Event> events;
        // 2n 个事件
            for(auto& interval: intervals){
            int left = interval[0];
            int right = interval[1];
            int len = right - left + 1;
            // 2n 个事件
            events.push_back({1,left,len});
            events.push_back({-1,right,len});
        }
        // m 个事件
        for(int i = 0; i < queries.size(); i++){
            events.push_back({0,queries[i],i});
        }
        sort(events.begin(), events.end(), [&](const Event& a, const Event& b){
            return a.pos < b.pos || (a.pos == b.pos && a.type > b.type);
        });
        map<int, int> values;
        vector<int> ans(queries.size());
        for(auto& event: events){
            if(event.type == 1){
                values[event.length]++;
            }else if(event.type == -1){
                values[event.length]--;
                if(values[event.length] == 0) values.erase(event.length);
            }else{
                int index = event.length;
                if(values.empty()) ans[index] = -1;
                else ans[index] = values.begin()->first;  // min value
            }
        }
        return ans;
    }
};