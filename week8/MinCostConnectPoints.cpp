class MinCostConnectPoints {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 按题面，初始化各点出边信息
        vector<vector<int>> edges;
        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                edges.push_back({i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
            }
        }
        // 根据最小费用目标，按权值排序
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });

        // Kruskal算法：并查集维护各点之间关系
        // 初始化：points.size() 个集合
        for(int i = 0; i < points.size(); i++) father.push_back(i);

        int ans = 0;
        for(int i = 0; i < edges.size(); i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int z = edges[i][2];
            // 未连接的点：更新连接关系
            if(find(x) != find(y)){
                ans += z;
                father[find(x)] = find(y);
            }
        }
        return ans;
    }

private:
    vector<int> father;
    int find(int target){
        if(target == father[target]) return target;
        return father[target] = find(father[target]);
    }
};