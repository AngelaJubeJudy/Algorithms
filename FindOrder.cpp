class FindOrder {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;

        edges = vector<vector<int>>(n ,vector<int>());
        inDeg = vector<int>(n, 0);


        for(vector<int>& pre: prerequisites){
            int u = pre[0];
            int v = pre[1];
            addEdge(u, v);
        }
        return topsort();
    }

private: 
    vector<int> topsort(){
        vector<int> learned;
        queue<int> q;
        for(int i=0; i<n; i++){
            if(inDeg[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            learned.push_back(x);
            for(int y: edges[x]){
                inDeg[y]--;
                if(inDeg[y] == 0) q.push(y);
            }
        }
        reverse(learned.begin(), learned.end());
        if(learned.size() < n) return {};
        return learned;
    }

    void addEdge(int x, int y){
        edges[x].push_back(y);
        inDeg[y]++;
    }

    int n;
    vector<vector<int>> edges;
    vector<int> inDeg;
};