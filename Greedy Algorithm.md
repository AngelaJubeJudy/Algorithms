# Topic Ⅷ: Greedy Algorithm

## 贪心算法理论
* 算法
    * 每一步：当前状态下的最优决策，“`局部最优`”（希望是“全局最优）
    * 缺点：结果不一定正确
    * 优点：更好的时间复杂度

## 实战
* 入门
    * [322.零钱兑换](https://leetcode-cn.com/problems/coin-change/)
        * 贪心策略：先用能用的选择里的较大面值
        * 贪心前提：大面值是小面值的`倍数关系`！！！
        * 搜索：遍历状态空间；（剩余金额，硬币数量）
        * 贪心的基本证明方法——`“决策包容性”`：几种决策/出边，都能通过可达步骤到所有点，未来的可能性没有减少。

* 证明：“面值互相构成倍数时”
    * [860.柠檬水找零](https://leetcode-cn.com/problems/lemonade-change/description/)
    * [455.分发饼干](https://leetcode-cn.com/problems/assign-cookies/description/)
        * 一块饼干总是要满足一个孩子
        * 同样的饼干，分给`刚刚好能满足的`孩子
        * 思路：大饼干给大胃口孩子
        * 逆向思路：当前小孩子吃最小的饼干（小饼干不能满足小孩子，肯定也不能满足中孩子和大孩子了，舍弃）

* 证明：“决策范围扩展”
    * [122.买卖股票的最佳时机Ⅱ](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)
        * 多走几步验证可行性：之后要涨，先不卖
        * 收益范围：prices[i] - prices[i-1] > 0，收获所有上涨区间的所有收益。
    * [45.跳跃游戏Ⅱ](https://leetcode-cn.com/problems/jump-game-ii/)
        * 不影响问题的解，缩减了问题规模

* 证明：“邻项交换”
    * [1665.完成所有任务的最少初始能量](https://leetcode-cn.com/problems/minimum-initial-energy-to-finish-tasks/)
        * 两个属性都会影响决策：门槛，当前任务消耗
        * 不能简单排序两个属性，按什么顺序做是关键
        * `按照"门槛 - 消耗"升序排序`，以该顺序完成所有任务
        * 先做：消耗小，门槛高！！！
