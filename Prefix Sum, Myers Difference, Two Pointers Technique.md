# Topic Ⅱ: Prefix Sum, Myers Difference, Two Pointers Technique

## Contents
* 求子段和，且满足区间减法性质————前缀和算法
    * “区间减法性质”：[l,r]的信息可以由[1,r]和[1,l-1]的信息推到而出。
* 维护的信息是关于一个点的————双指针算法
* 维护的信息是一整个候选集合————单调队列


## Prefix Sum 前缀和
* 构建一维数组：s[i] = A的前i个元素值相加。
    * 当A中都是非负数，前缀和数组S单调递增。
* 基本应用：TC = O(1) 求第l到第r的数组`子段和`。
    * sum(l, r) = S[r] - S[l-1].
* 实战：[1248.统计“优美子数组”](https://leetcode-cn.com/problems/count-number-of-nice-subarrays/)
    * 读题：求有多少个子数组含k个奇数。
    * 思路：每个元素先对2取模，变为奇偶性；再求和为k的连续子数组（变为“前缀和”问题）。
    * 问题主干：对每个r（1到n），考虑有几个l（1到r），使得s[r] - s[l - 1] = k.
    * 改写上一条：对每个i（1到n），考虑有几个j（0到i-1），使得s[i] - s[j] = k ——“换元”。
    * 改写上一条：对每个i（1到n），考虑有几个s[j]使得s[i] - k.

* 二维前缀和
    * 前缀和数组：S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j].
    * 子矩阵和：sum(p, q, i, j) = S[i][j] - S[i][q-1] - S[p-1][j] + S[p-1][q-1]
    * 本质：“`容斥`”的思想
    * TC: 预处理，O(n^2)；询问，O(1)
* 实战：[304.二维区域和检索-矩阵不可变](https://leetcode-cn.com/problems/range-sum-query-2d-immutable/)
    * 只查询不修改
    * i和j从1开始
    * 有`模板`！！！


## Myers Difference 差分
* 差分数组B：B[i] = A[i] = A[i-1], where B[1] = A[1] and 2<=i<=n.
* 前缀和的逆运算：`前缀和求差分就是原数组A`；cal_difc(cal_sum(A)) = A.
* 相加的数字，在相减的过程中相互抵消掉了，两边的没抵消
* 实战：二维区域查询且修改
    * 暴力：O(m*n)，优化：O(m+n)
    * 应用：[1109.航班预订统计](https://leetcode-cn.com/problems/corporate-flight-bookings/)
    * 思想：对l到r一段数加一个值，这个影响从l开始到r+1结束；最后`累加“影响”，就是对差分求前缀和`。 
    * 总结：任何对于区间的操作（例，“区间覆盖问题”问被覆盖的总长度），可以转化为2个关键点。事件的影响。——`面试常考题`
* 实战：[53.最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)
    * 思路一——“前缀和+前缀最小值”：固定i（枚举右端点i），看哪个j使得s[i]-s[j]值最大（即枚举s[i]让s[j]最小；先处理min(s[j])，使用O(n)的空间换取时间）。
        * hint：前缀最小值/前缀最大值也可以用“前缀和算法”实现。
    * 思路二——“贪心”：和为正，向右扩展；和为负，舍弃当前子序列。


## Two Pointers Technique 双指针扫描 & Sliding Window 滑动窗口
* 解决的问题：`基于子段`的统计问题
    * 子段：数组中连续的一段。
* 朴素：O(n^2)，两重循环的枚举。
* 优化：两个指针一起移动、相向移动，去除冗余枚举。
    * 优化一：固定右端点，看左端点的取值范围（用前缀和去维护一些信息）
    * 优化二：移动一个端点，看另一个端点的变化情况（移动i看j的变化情况）
        * `一个端点跟随另一个端点单调移动`————滑动窗口问题
        * 实现方式：双指针扫描
* 实战
    * [1.两数之和](https://leetcode-cn.com/problems/two-sum/)
        * 排序 + 双指针扫描
        * 借助哈希实现
    * [15.三数之和](https://leetcode-cn.com/problems/3sum/)
        * 思考：避免重复，相同元素不二次枚举
        * 复用两数之和
    * [11.盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)
        * 思考：盛水量由短的决定
        * 实现：双指针扫描，每次移动短的对应的指针


## Monotonic Stack 单调栈 & Monotonic Queue 单调队列
### 单调栈
* 思路：确定递增递减
    * 关键：考虑`“前面不能影响后面”的条件`，便于单独计算
    * `解题模板`：循环每个元素，先判断`栈顶与该元素是否满足单调性`。若不满足，弹栈，更新答案，累加宽度；若满足，入栈。

* 实战：[84.柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)
    * 模板题，建议练习

### 单调队列
* 思路
    * 单调队列维护的是候选集合：时间也具有单调性（前旧后新）。
    * 每个候选项的某个属性也具有单调性。
    * 确定递增递减：确定任意两个候选项j_1 < j_2，写出 j_1 比 j_2 优的条件。
    * 排除冗余：j_1 < j_2，且 j_1 比 j_2 差，则舍弃j_1候选项。
    * `解题模板`：循环每个元素，先判断`对头是否过期`。若过期，对头出队。若未过期，取对头为最佳候选项，计算答案。下一步，判断`队尾与新元素是否满足单调性`。若不满足，队尾出队（舍弃）；若满足，新元素入队。

* 实战：[239.滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)
    * 经典题！！！
    * `冗余`：expire_time(i) < expire_time(j)则i先出界；又nums[i] < nums[j]，则i判定为冗余候选项，舍弃
    * 头部最优（值递减）
    * 合法性：头部过期，出队
* 思路选择！！！
    * 关于`点`的（和中间无关的）——双指针
    * 关于`一段`——单调队列（不满足区间减法性质；两个属性，时间和顺序） / 前缀和（满足区间减法性质）

* 实战
    * [560.和为k的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)
    * [42.接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)








