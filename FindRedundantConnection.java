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
            dfs(1, -1);
            if(hasCycle) return edge;
        }
        return null;
    }

    // 深度优先遍历找环：对图DFS会产生一棵搜索树
    private void dfs(int x, int father){
        visited[x] = true;
        System.out.println("Father: " + father + ", x: " + x);
        System.out.println("Has Cycle? " + hasCycle);

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

/*
输入：[[2,7],[7,8],[3,6],[2,5],[6,8],[4,8],[2,8],[1,8],[7,10],[3,9]]
预期输出：[2,8]
实际输出：[1,8]
打印结果：
edge: 2, 7
Father: -1, x: 1
Has Cycle? false
edge: 7, 8
Father: -1, x: 1
Has Cycle? false
edge: 3, 6
Father: -1, x: 1
Has Cycle? false
edge: 2, 5
Father: -1, x: 1
Has Cycle? false
edge: 6, 8
Father: -1, x: 1
Has Cycle? false
edge: 4, 8
Father: -1, x: 1
Has Cycle? false
edge: 2, 8
Father: -1, x: 1
Has Cycle? false-------------------------------上一次无环
edge: 1, 8
Father: -1, x: 1
Has Cycle? false-------------------------------上一次应该有环了
Father: 1, x: 8
Has Cycle? false
Father: 8, x: 7
Has Cycle? false
Father: 7, x: 2
Has Cycle? false
Father: 2, x: 5
Has Cycle? false
Cycle!!! Has visited: 8
Father: 8, x: 6
Has Cycle? true
Father: 6, x: 3
Has Cycle? true
Father: 8, x: 4
Has Cycle? true
Father: 8, x: 2
Has Cycle? true
Father: 2, x: 7
Has Cycle? true
Cycle!!! Has visited: 8
Father: 2, x: 5
Has Cycle? true

*/