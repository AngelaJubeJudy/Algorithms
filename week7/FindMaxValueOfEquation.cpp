class FindMaxValueOfEquation {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = -1000000000;
        // 存下标
        deque<int> q;
        for(int i = 0; i < points.size(); i++){
            // step 1: 队头的合法性判断
            while(!q.empty() && points[q.front()][0] < points[i][0] - k){
                q.pop_front();
            }

            // step 2: 取队头为最优解
            if(!q.empty()) ans = max(ans, points[i][1] + points[i][0] + points[q.front()][1] - points[q.front()][0]);

            // step 3: 维护队列单调性，队尾插入新元素
            while(!q.empty() && points[q.back()][1] - points[q.back()][0] <= points[i][1] - points[i][0]){
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans;
    }
};