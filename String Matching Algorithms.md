# Topic Ⅹ-Ⅱ: String Matching Algorithms

## 字符串基础知识
* 字符串：序列化后的信息，表示复杂信息的一种方式
* 考察：熟练工，对算法考察不多
* 各语言的实现
* 遍历
* 比较
    * C/C++, Python: x == y; TC = O(n).
    * JAVA: x.equals(y), x.equalsIsIgnoreCase(y) 比较值; x == y 比较是否为同一对象。

* 实战
    * [709.转换成小写字母](https://leetcode-cn.com/problems/to-lower-case/)-----E
    * [58最后一个单词的长度](https://leetcode-cn.com/problems/length-of-last-word/)-----E
    * [771.宝石与石头](https://leetcode-cn.com/problems/jewels-and-stones/)-----E
    * [387.字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)-----E
    * [14.最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/description/)-----E
    * [344.反转字符串](https://leetcode-cn.com/problems/reverse-string/)-----E
    * [541.反转字符串Ⅱ](https://leetcode-cn.com/problems/reverse-string-ii/)-----E
    * [151.翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/)-----M
    * [557.翻转字符串里的单词Ⅲ](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)-----E
    * [917.仅仅反转字母](https://leetcode-cn.com/problems/reverse-only-letters/)-----E
    * [8.字符串转换成整数](https://leetcode-cn.com/problems/string-to-integer-atoi/)-----M
        * 哪些情况影响i的变化：遇到前导空格、字母，正负号，终止条件（非数字）。

## Rabin-Karp 字符串哈希算法
* 字符串s，模式串t
    * 朴素：TC = O(nm)
    * Rabin-Karp: TC = O(n+m)，基于哈希
* 哈希：`字符串s看作b进制数（一个多项式），计算在十进制下对一个整数p取模的值`。
    * 任意进制转十进制的方法：幂函数多项式
    * 十进制转任意进制：短除法
    * 取模运算具有分配律
    * 选取的b和p决定了哈希函数质量：根据经验，b=131或13331，p为大质数，`冲突概率极小`。
    * 无符号的32位整数上界是2^32，无符号的64位整数上界是2^64；p取2^64，无符号数值若越界，等价于取模（无符号从0开始，有符号从负最小开始；整数是一个环）。
    * 计算任意子串的哈希值：H[i], for i = 0 to n-1
    * O(n)空间计算，先预处理计算前缀子串的哈希值
* 万金油解法

* 实战
    * [28.实现strStr()](https://leetcode-cn.com/problems/implement-strstr/)-----E
        * C++ 的库函数
    * [686.重复叠加子串穿匹配](https://leetcode-cn.com/problems/repeated-string-match/)-----M

## 典型的字符串处理
* 实战
    * [125.验证回文串](https://leetcode-cn.com/problems/valid-palindrome/)-----E
    * [680.验证回文串Ⅱ](https://leetcode-cn.com/problems/valid-palindrome-ii/)-----E
    * [5.最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)-----M
        * 枚举中间点：TC = O(n)；分奇偶，中间是一个字符或一个空。
        * 枚举做右端点，比较子串哈希：TC = O(n^2)
        * 朴素：TC = O(n^3)
        * 验证回文用哈希，枚举左右端点用二分进行优化

    * [205.同构字符串](https://leetcode-cn.com/problems/isomorphic-strings/)-----E
    * [242.有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)-----E
    * [49.字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)-----M
    * [438.找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)-----M
    * [10.正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/)-----H
    * [115.不同的子序列](https://leetcode-cn.com/problems/distinct-subsequences/)-----H
    * [44.通配符匹配](https://leetcode-cn.com/problems/wildcard-matching/)-----H


## 字符串模式匹配：KMP算法
* 字符串匹配
    * 暴力：O(nm)，两重循环，第一重是开始位置O(n)，第二重是模式串t的位置O(m).
    * 暴力的优化（`省略内层循环`）：RK算法，O(n)空间`预处理`所有前缀哈希值，后续O(1)时间得到子串哈希值；然后枚举开始位置O(n)时间循环。
    * strStr() 实现模板

* Rabin-Karp 字符串匹配
    * TC = O(n+m)
    * 模式串t，长度m；文本串s，长度n
    * 计算哈希值：模式串t，TC = O(m)；文本串中每个长度为m的子串的哈希，共计计算 n-m+1 次。
    * 哈希值比较：相同，用朴素算法再次判断（若哈希函数选的好，可省略此步骤）；不同，不匹配。
    
* KMP 模式匹配算法  
    * TC 常数更小，更快：TC = O(n+m)
    * 思考：避免s中重复位置的比较，s什么时候参与运算？
    * 改进：`先对模式串进行“自匹配”`（计算数组next）
    * 数组 next：next[i] 表示模式串中以 i 结尾的子串与模式串的前缀能匹配的最长长度；等于0表示不存在。（next[i] 即`在模式串的i位置之前，模式串的头部之后`的范围里能匹配的最长长度）
        * 初始化：next[1] = 0;
        * 匹配：next[i] = next[i-1] + 1；不用再次比较，也不用枚举起始位置。
        * 不匹配：跳过已匹配部分（残余匹配，不完整），起始位置向后继续重新匹配。
        * 意义：告诉下一个比较的子串，跳过冗余比较（通过next[i] ）
        * 循环：一个for循环i位置（每层for，j值最多增加1次1，j增加最多n次），一个while循环j位置（j非负：j增加最多m次，while循环会让j减小）
    * 学习`模板`！！！


# 高级搜索
* P问题：多项式时间算法；实际中很少
* NP问题：更多；指数级时间求解，只能搜索，指数级遍历状态空间
    * 优化手段：剪枝，双向，启发式

## 搜索剪枝
* 蛮力搜索
    * 指数型，TC = O(k^n)
        * 例：子集问题，大体积背包TC = O(n*V，上亿，数组存不下；n个物品，选or不选，2^n)
    * 排列型，TC = O(n!)
        * 例：全排列，旅行商（n点图，遍历每个点有且只有一次，求好方法），N 皇后（A_1...n的排列）
    * 组合型
        * 例：组合选数

* 初级搜索
    * BFS
    * DFS
    * 优化：判重（避免某些状态的重复搜索）
    * 状态空间
    * 搜索树

* 搜索`剪枝`
    * 蛮力搜索/回溯：试错
    * 优化点（`尽量减少分支数量`）：通过已有信息，判定某些分支不可行/不优；减少要访问的状态数量

* 实战
    * [22.括号生成](https://leetcode-cn.com/problems/generate-parentheses/)-----M
        * 不合法状态：左右括号数量不相等
    * [51.N皇后](https://leetcode-cn.com/problems/n-queens/)-----H
        * 不合法状态：
    * [36.有效的数独](https://leetcode-cn.com/problems/valid-sudoku/)-----M
    * [37.解数独](https://leetcode-cn.com/problems/sudoku-solver/)-----H
        * 蛮力搜索：每次找`第一个`空位置（即找一个空填；各自没有顺序关系，不要每次枚举空位置；`每层就是9个分支`）
        * 优化一：剪枝
        * 优化二：顺序剪枝（使扩张缓慢），先找最确定的

## 迭代加深，折半搜索，双向搜索
* BFS 
    * 一般 BFS
    * 双向 BFS：起点和终点唯一时，从两边出发；中间相遇，停止搜索。
        * 好处：适用于宽树，有些分支到不了终点的情况，避免太宽。
    * 实战
        * [127.单词接龙](https://leetcode-cn.com/problems/word-ladder/)-----H

* 迭代加深
    * 对 DFS 的优化：避免太深
    * 适用问题：集合类；把集合一分为二，分别搜出所有方案，再合并。
    * 方法：限制搜索深度

* 折半搜索
    * 类似于双向 BFS 


* 实战
    * [773.滑动谜题（五数码）](https://leetcode-cn.com/problems/sliding-puzzle/)-----H
    * [八数码](https://www.acwing.com/problem/content/847/)
    * [八数码](https://www.acwing.com/problem/content/181/)
    * [1091.二进制矩阵中的最短路径](https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/)-----M

## 启发式搜索：A* 算法 
* 复习
    * 普通 BFS：按`层`扩展（处理无权/边权为1的问题）
        * 终点第一次被遍历到，即为最优解
    * 优先队列 BFS：每次从队列中取出`当前代价最小`的状态，进行扩展
        * 贪心思想：缺少对未来的估计
        * 第一次终点被从堆顶取出，即为最优解

* A* 算法
    * 智能估计局面
        * 以任意状态为输入，计算从该状态到终点状态所需代价的估计值
        * 实现：优先扩展`“当前代价+未来估价”最小的状态`进行扩展
    * 关键：设计一个“`估价函数`”
        * 设计原则：估价必须比实际更优
            * 所有 f=0：退化为优先队列 BFS
            * 估价越精准，效率越高
        * 好状态估计差：错误答案。大代价压在堆中无法取出，从而在非最优搜索路径上的状态不断扩展。————否决正确
        * 坏状态估计好：值比最优解更早地取出。多算了几个垃圾状态。————多看错误
    * 求第k短路（最短 <= 第k短）
        * 最短可作为估价函数

* 实战
    * [773.滑动谜题（五数码）](https://leetcode-cn.com/problems/sliding-puzzle/)-----H
    * [八数码](https://www.acwing.com/problem/content/847/)
    * [八数码](https://www.acwing.com/problem/content/181/)
    * [1091.二进制矩阵中的最短路径](https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/)-----M


