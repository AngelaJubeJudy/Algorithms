# Topic Ⅸ: Dynamic Programming

# Dynamic Programming Ⅰ
## `从“搜索”开始`

## 零钱兑换
* 硬币可选面额集合 coins，目标金额 amount
    * 影响整体的变量：coins是静态的（无限次取coin）；amount和硬币数量是`动态变化`的
        * 定义状态：（剩余金额，硬币数）
    * 搜索遍历整个空间
    * 目标：到达终点（0元）
    * 另：`子问题的最优解`推导出问题的最优解
        * `最优子结构`：有初始状态；每个状态有最优化目标，状态之间可推导；对每个 amount 只算一次。
        * 新目标：硬币最少
        * `搜索问题 --> 优化问题`
* 方法一：`递推`
    * 循环状态，每个状态内循环决策
    * TC = O(amount * #coins)
* 方法二：记忆化（=`递归`）
    * `自上而下`的思维 
    * TC = O(amount * #coins)
    * 每个状态只遍历一次

## 动态规划
* 算法：定义状态 + 最优子结构（代表） + 推导关系
* `自下而上`的思维
* 耗时：TC一致，但动规更快
    * TC = O(amount * #coins)
* 一般`递推`实现
    * 问题的状态空间是一张有向无环图
* 题解
    * `状态转移方程`（大半工作）
    * 目标
    * 边界
* 三要素
    * 阶段：线性增长
    * 决策：用i找到子问题
    * 状态：子问题的目标，最优子结构

* 实战：[63.不同路径Ⅱ](https://leetcode-cn.com/problems/unique-paths-ii/)---M
    * 不变信息：障碍物位置。
    * 状态：人的位置 start: (i, j), 下一步 end
    * 解法一：DFS + 记忆化
        * Bottom-Up: f[i, j] = f[i+1, j] + f[i, j+1]
    * 解法二：BFS + 记忆化
        * Top-Down: f[i, j] = f[i-1, j] + f[i, j-1]
    * 解法三：动归（递推）
        * 状态：[i, j]
        * 递推：目标 f[i, j] = f[i-1, j] + f[i, j-1] 两种决策
        * 边界：0行，0列

* 实战：[1143.最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)---M
    * 按顺序，可以有间隔
    * 人力模拟：看看需要维护什么变量？
        * text1[i]: text1 的前 i 个字符
        * text2[j]: text2 的前 j 个字符
        * 求 text1[i] 和 text2[j] 的最长公共子序列
    * 转移方程
        * f[i, j] = f[i-1, j-1] + 1 与 f[i, j] = max(f[i-1, j], f[i, j-1])
    * 阶段：[i, j]，线性增长的轮廓
    * 边界：0行，0列
    * 存转移路径：记忆“用了哪一个决策”，从哪来的，O(1) 空间记忆

* 实战：[300.最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)---M
    * 搜索：指数型
    * 第i个选不选；第一状态
    * 动规的值：最长子序列
    * 记忆：上一个选在哪了（结尾的数）；第二状态
    * 状态 = f[i][val] --> `f[i]：前 i 个数组成的以a[i]结尾的最长上升子序列的长度。`
    * N 种决策（循环） = 选 i / 不选 i
    * 边界：f[i] = 1
    * `决策和状态的平衡：决策越多，状态越简单；决策越少，状态转移越复杂`
    * O(N*logN): 贪心，二分（辅助贪心的查找和修改）

* 实战：[53.最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)---E
    * f[i]：以 nums[i] 为结尾的最大子序和
    * 边界：f[0] = nums[0]
    * 贪心：当前和为负，不选，清零，从新开始

* 实战：[152.乘积最大子数组](https://leetcode-cn.com/problems/maximum-product-subarray/)---M
    * f[i]：以 nums[i] 为结尾的最大子序积
    * max 为代表时，最大子序和的推导方法不满足最优子结构
        * ∴ 选`2个代表`：存一个 max，存一个 min

* 作业
    * [70.爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/description/)---E
    * [120.三角形最小路径和](https://leetcode-cn.com/problems/triangle/description/)---M
    * [673.最长递增子序列的个数](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/)---M

## 总结
### 解题方法
* 人力模拟 / 暴力搜索 
* 看轮廓：定义状态
* 选代表 & 代表间的推导关系：确定最优子结构
* 关注决策：写出转移方程
* 考虑边界：确定边界、目标，递推实现
* 打印方案：记忆转移路径，然后递归复原
* 何时包含结尾？
    * 结尾是否参与运算，是否需要连续
### 什么是最优子结构



# Dynamic Programming Ⅱ
## 复杂的线性动态规划问题
### 实战：买卖股票
#### [121.买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)
* 一笔交易，获取最大利润
    * 枚举分界点
    * 贪心解法

#### [122.买卖股票的最佳时机Ⅱ](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)
* 多次交易，每次买卖一股

#### [123.买卖股票的最佳时机Ⅲ](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)
* 两笔交易（两次买卖）

#### [188.买卖股票的最佳时机Ⅳ](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)
* k笔交易
* 1~3的通用版
* 模拟炒股时的关注点
    * prices[i] 每天的价格————不变，属于共享的输入变量
    * 第i天
    * 仓位j（是否有持仓，决定买/卖）
    * 赚多少钱————最优化的目标，求max
    * 交易次数 < k
* 决策：买 / 卖

#### [714.买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)
* 手续费

#### [309.买卖股票最佳时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
* 冷冻期 


## 解题流程
### Step 1：提取关键信息
* 模型
    * 共同点：只能持有一股
    * 不同点
        * 交易次数 k
        * 是否冷冻期
        * 是否手续费
* 限制：不能从f[0, 1]卖，即f[0, 1]不合法。
* 边界：f[0,0] = 0，其他初始化为`负无穷`（求max时的简化转移技巧）。
    * 0作为边界。

### Step 2：状态变量
* 天数 i
* 买卖决策 j
* 交易次数 k

### Step 3：`状态转移方程`
#### `简化版`
* 增加一维信息：k
    * 0 <= k <= c
    * TC = O(n*c)
* 状态转移过程：TC = O(1)
    * 买：𝑓[𝑖,1,𝑘] ← 𝑓[𝑖−1,0,𝑘−1] - 𝑝𝑟𝑖𝑐𝑒𝑠[𝑖]
    * 卖（赚）：𝑓[𝑖,0,𝑘] ← 𝑓[𝑖−1,1,𝑘] + 𝑝𝑟𝑖𝑐𝑒𝑠[𝑖]
        * 买算过一次交易了，所以卖操作 k 不计数
    * 休息：f[i,j,k] ← f[i-1,j,k]
* 初态：f[0,0,0] = 0；其他负无穷。

#### `升级版`
* 手续费：定值（非动规状态），买的时候扣费。
* 冷冻期：随买卖变化。l等于0或1，放入动规方程。
* 终极方程
    * 买（扣手续费&不在冷冻期）：𝑓[𝑖,1,𝑘,0] ← 𝑓[𝑖−1,0,𝑘−1,0] - 𝑝𝑟𝑖𝑐𝑒𝑠[𝑖] - fee
    * 卖（赚）：𝑓[𝑖,0,𝑘,1] ← 𝑓[𝑖−1,1,𝑘,0] + 𝑝𝑟𝑖𝑐𝑒𝑠[𝑖]
    * 休息：f[i,j,k,0] ← f[i-1,j,k,l]；l = 0 or 1，无所谓前一天冷冻还是正常.
* 初态：f[0,0,0,0] = 0；其他负无穷。
* TC = O(n*c)

### 思考
* DP vs 贪心
    * 无交易次数：可贪心。
    * 有k：决策需要基于全局考虑，买卖次数对全局有影响。
    * 贪心能不能用？取决于局部最优是否能推导出全局最优。
* 状态与决策的平衡选择
    * 原理：状态包含的信息越多，决策越简单；状态越简单，决策越复杂。
    * 技巧：关注信息全部放在状态中。（除非规模很大，再考虑优化）
    * 实战类比：[300.最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)
* 状态转移方程的2种写法（递推的2种写法）
    * `列表法`
    * 2种写法
        * 入边：哪个状态能到 f[i][j][k][l]
        * 出边：f[i][j][k][l] 能到哪个状态
* 空间优化
    * 思考：相邻天的转移，从 i-1 到 i。
    * 优化方法：`滚动数组`，本质是`复用`空间。
    * 用法：在第一维 mod 2，即 f[i&1][j][k][l].
* 冷冻期 d 天
    * l 从 0 到 d。
* 最多持仓 t 股
    * j 从 0 到 t。

## 复杂实战：打家劫舍
* [198.打家劫舍](https://leetcode-cn.com/problems/house-robber/)
    * 关注信息：当前第i间房，j = 偷/不偷
    * 转移
        * 不偷：f[i,0] = max(f[i-1,1], f[i-1,0])
        * 偷：f[i,1] = f[i-1,0] + nums[i]
    * 初值：f[0,0] = 0.

* [213.打家劫舍Ⅱ](https://leetcode-cn.com/problems/house-robber-ii/)
    * 第 1 间和第 n 间相邻：出现`环`
    * 解法：`“滚动型”DP`————断开一条边
    * 两次 DP
        * 第一次：预设1偷，则n不偷。f[1,0] = 0, f[1,1] = -∞，目标为 max(f[n,0], f[n,1]).
        * 第二次：预设1不偷，则n偷。f[1,0] = 0, f[1,1] = nums[1]，目标为f[n,0].

* 高频题： [72.编辑距离](https://leetcode-cn.com/problems/edit-distance/)

## 背包
* 0-1背包
    * n个物品，第i个物品体积V价值W。背包M容积。
    * 基础版
        * 关注：i物品要/不要，放了多少物品（保证当前总容积 j<=M）。
    * 优化版
        * 滚动数组优化: i mod 2, TC = O(n*m) --> O(2m).
        * 进一步: f[j] 变为一维数组，因为不选时是直接拷贝。注，此时`j需要倒序循环`。
        * 上述解惑：否则价值高体积小的那个物品会被拿多次。先更新再？？？。
        * 正序循环：完全背包问题。
* 实战：[416.分割等和子集](https://leetcode-cn.com/problems/partition-equal-subset-sum/)
    * 类比0-1背包问题————体积：数值，价值：无。
    * 以sum为，伪多项式算法：问题很小，时间很长。

* 完全背包：第i种物品有无数个。
    * 实际问题：零钱兑换。
    * 基础版
    * 优化版
* 实战：[518.零钱兑换Ⅱ](https://leetcode-cn.com/problems/coin-change-2/)
    * 空集：算一种方案。
    * 正序循环：累积方案数
    * 先循环coins，再循环amount
        * WHY? 动规先循环阶段！！！

## 总结
* DP：`有序`、`不重复`的遍历，相当于状态图上的拓扑排序。
* 找关键 --> 人工模拟 --> 定义状态
* 滚动数组优化空间
* 环形问题的处理
* 背包
* 计数原则：不漏解
    * 动规计数原则：不漏不重解

## 练习
### [279.完全平方数](https://leetcode-cn.com/problems/perfect-squares/)
### [55.跳跃游戏](https://leetcode-cn.com/problems/jump-game/)
### [45.跳跃游戏Ⅱ](https://leetcode-cn.com/problems/jump-game-ii/)



# Dynamic Programming Ⅲ
## 动态规划的优化
* 第一步
    * 去掉绝对值计算步骤。
    * 思考：j 有必要循环 1~n 吗？j > i 和 j < i 的情况绝对值相同。
* 第二步
    * i 影响的部分和 j 影戏的部分分开计算：两个子问题。
    * max(tmp, y[j] - x[j]), ans = max(ans, y[i] + x[i] + tmp).
    * 思考：动规中，状态和决策的循环在不同层处理。
* 第三步
    * 思考：对于每个 i，都算了哪些 j 相关的算式？
    * 列出每次计算的结果，比较，看看有什么冗余。
* 动态规划的转移优化
    * `分离状态变量和决策变量`
    * 观察决策候选集合（观察集合随状态变量的变化情况）
        * 只有插入：本实例
        * 既有插入又有删除：用堆等维护
* 实战
    * [1499.满足不等式的最大值](https://leetcode-cn.com/problems/max-value-of-equation/)
        * x_i 和 x_j 不能相距太远：|x_i - x_j| < k.
        * i 变大，j 的上界、下届单调递增，∴滑动窗口问题。
    * [918.环形子数组的最大和](https://leetcode-cn.com/problems/maximum-sum-circular-subarray/)
        * 思考非环形时怎么做：子段和就是前缀和相减。
        * 先枚举头前缀和，再枚举后一段的前缀和：即求后缀和的max。
        * 先求非环形的最大字段和，再求非环形最小字段和。
        * 思考：max(头 + 尾) = min(总和 - 头 - 尾).
        * Q：头尾相接如何计算和？
        * A：转换 ===> 在`长为 2n 的副本`上，求长度不超过 n 的最大字段和。（长度为 n 的滑动窗口），求滑动窗口最小值。


## 区间动态规划
* 阶段：区间长度（从小到大计算）。
* 分段思想和“分治”类似。
    * 可以用 DFS 实现。（运行时间较长）
* 实战
    * [312.戳气球](https://leetcode-cn.com/problems/burst-balloons/)
        * 暴力：O(2^n)
        * 先戳p？区间：1 ~ n ==> left ~ right. 子问题和l & r 不是同类子问题了！！！
        * 最后戳p？决策。初值，f[l, r] = 0.

    * [1000.合成石头的最低成本](https://leetcode-cn.com/problems/minimum-cost-to-merge-stones/)
        * 难点：状态定义。
        * 子问题难划分。
        * 思考：状态和决策的平衡。
        * 决策二（带子问题的决策）的优化。
        * 类比“括号匹配问题”。


## 树形动态规划
* 与线性动态规划的区别：基本没有。
    * 树形动态规划：套在 DFS 里的动态规划。
* `子问题：子树`。
    * 状态：以 x 为根的子树。
    * 决策：x 的子节点。
* 实战
    * [337.打家劫舍Ⅲ](https://leetcode-cn.com/problems/house-robber-iii/)




