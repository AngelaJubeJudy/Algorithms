# Topic Ⅹ: Trie, Disjoint Set

## 字典树：Trie
* 经典面试题：搜索提示
    * 字典树存储语料库。

* 基本结构、基本性质
    * 结点和带有字符的边。
    * 用途：排序大量的字符串，统计词频等；最大程度减少字符串的比较，查询效率更高。
    * 结点：存储其他信息；例，词频（存储在字符串结尾）、出现次数。

* 内部实现
    * “`字符集数组法`”：在每个结点存储一个出边数组，固定长度为26（英文字母个数）
        * 适用于较小字符集。
        * 以字符为下标，保存指向的结点。
        * TC = O(词长)，线性查询。
        * SC = O(结点数*字符集大小)
        * 以空间换时间。
    * “`字符集映射法`”：每个结点上存储映射（词频，hash map；排序，ordered map）
        * 适用性广，适合较大字符集。
        * SC = O(文本字符总数)
        * TC = O(k*词长)，线性查询，常数稍大。

* 核心思想
    * 空间换时间（字符集数组/字符集映射）
    * 公共前缀降低了查询开销
    * 分组思想——前缀相同的字符串

* 实战
    * [208.实现 Trie](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)
    * [212.单词搜索Ⅱ](https://leetcode-cn.com/problems/word-search-ii/)


## 并查集：Disjoint Set
* 基本用途
    * 处理不相交集合的合并和查询
    * 广泛用途：分组问题；维护无序的二元关系

* 基本操作
    * 建立
        * 结点存储其父节点
    * 合并
        * 各集合根的合并
        * 优化：启发式合并，TC = O(α(n))，其中α(n) <= 5.
    * 查询
        * 找根：较耗时
        * 优化：路径压缩（只关心根结点，所有结点都与根相连）

* 内部实现————树（无环无向）
    * 初始化：MakeSet
    * 合并：UnionSet
    * 查询 Find 
    * 路径压缩

* 实战
    * [547.省份数量](https://leetcode-cn.com/problems/number-of-provinces/)
    * [130.被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)
* Howework
    * [684.冗余连接](https://leetcode-cn.com/problems/redundant-connection/)
    * [200.岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)











