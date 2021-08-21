class GetSkyline {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // 每个建筑块拆分为2个事件：出现，消失
        vector<pair<int, int>> events;
        for(auto& building: buildings){
            int left = building[0];
            int right = building[1];
            int height = building[2];
            events.push_back({left, height});
            events.push_back({right, -height});
        }
        sort(events.begin(), events.end());  // 按坐标排序

        map<int, int> h;  // 维护映射关系：高度，出现次数
        vector<vector<int>> ans;
        for(int i = 0; i < events.size(); i++){
            int event = events[i].first;
            int operation = events[i].second;
            if(operation < 0){  // 消失
                h[-operation]--;
                if(h[-operation] == 0) h.erase(-operation);
            }else h[operation]++;  // 出现

            // 输出天际线中无连续的、相同高度的水平线
            if (i == events.size() - 1 || event != events[i + 1].first) {
                int height = 0;
                if(!h.empty()) height = h.rbegin()->first;  // 与最大值比较
                
                if (ans.empty() || height != ans.back()[1])
                    ans.push_back({event, height});
            }

        }
        return ans;
    }
};