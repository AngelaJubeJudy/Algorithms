class FindRedundantConnection {
    public int[] findRedundantConnection(int[][] input) {
        n = 0;
        for(int[] edge: input){
            int u = edge[0];
            int v = edge[1];
            n = Math.max(v, n);
        }

        edges = new ArrayList<List<Integer>>();
        visited = new boolean[n+1];

        // 初态：n个空的list
        for(int i=0; i<=n; i++){
            edges.add(new ArrayList<Integer>());
            visited[i] = false;
        }
        hasCycle = false;

        for(int[] edge: input){
            int u = edge[0];
            int v = edge[1];

            // 每加一条边，看是否有环
            addEdge(u, v);
            addEdge(v, u);

            for(int i=0; i<=n; i++) visited[i] = false;
            dfs(u, -1);  // 易错点：从哪个节点开始DFS
            if(hasCycle) return edge;
        }
        return null;
    }

    // 深度优先遍历找环：对图DFS会产生一棵搜索树
    private void dfs(int x, int father){
        visited[x] = true;
        // System.out.println("Father: " + father + ", x: " + x);
        // System.out.println("Has Cycle? " + hasCycle);

        // 遍历：注意无向图的环的判断
        for(Integer y: edges.get(x)){
            if(y == father) continue;
            if(visited[y]) hasCycle = true;
            else dfs(y, x);
        }
        visited[x] = false;
    }

    // 图的构建
    private void addEdge(int x, int y){
        edges.get(x).add(y);
    }

    // 出边数组
    private List<List<Integer>> edges;
    boolean hasCycle;
    private boolean[] visited;
    int n;
}
