class CanFinish {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // 思路：深度
        edges = new ArrayList<List<Integer>>();
        visited = new boolean[numCourses + 1];

        // 初态：n个空的list，n个未被访问的节点
        for(int i=0; i<=numCourses; i++){
            edges.add(new ArrayList<Integer>());
            visited[i] = false;
        }
        hasCycle = false;

        // 初始化边
        for(int[] edge: prerequisites){
            int u = edge[0];
            int v = edge[1];
            addEdge(u, v);
            addEdge(v, u);
        }

        // 若无环，继续深度遍历
        for(int i=0; i<=numCourses; i++){
           if (!visited[i]) dfs(i);
        }

        return !hasCycle;
    }

    // 深度优先遍历找环：对图DFS会产生一棵搜索树
    private void dfs(int x){
        visited[x] = true;

        // 遍历：注意无向图的环的判断
        for(Integer y: edges.get(x)){
            if (y == x) continue;
            if(visited[y]){
                hasCycle = true;
                return;
            }else{
                dfs(y);
                if(hasCycle) return;
            }
        }
    }

    // 图的构建
    private void addEdge(int x, int y){
        edges.get(x).add(y);
    }

    // 出边数组
    private List<List<Integer>> edges;
    boolean hasCycle;
    private boolean[] visited;
}