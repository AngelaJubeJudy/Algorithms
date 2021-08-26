# Topic Ⅵ: Binary Search, Ternary Search 

## 二分
### 二分查找
* 在具有`单调性`的序列上，且能通过索引`随机访问`
* 有模板
* 1.1 模板 lower_bound：查询第一个>=val的下标，不存在则返回array.length
    * `合法条件`：第一个>=val
    * `搜索范围`：选最小下标
* 1.2 模板
    * `合法条件`：最后一个<=val
    * `搜索范围`：选最大下标
* upper_bound “后继”：查询第一个>val的下标，不存在则返回array.length
    * 坑：查不到 / 查到了也不一定是答案
* 严谨写法
    * 【建议选这个】`左区间包含，右区间不包含`：终止于left == right
    * 都不包含：终止于left > right
    * 都包含：终止于left + 1 == right
* 边界
    * left = -1, right = n - 1：终止于left >= right，保证了不存在时返回-1
    * left = 0; right = n：终止于left > right
* 实战
    * easy: [704.二分查找](https://leetcode-cn.com/problems/binary-search/)
    * medium: [34.在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
    * easy: [69.x的平方根](https://leetcode-cn.com/problems/sqrtx/)
    * [74.搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)
    * medium: [153.寻找旋转排列数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)
        * 整体单调，局部不单调
        * 解题思路：`关于条件单调，就可以使用二分`；值域，满足 / 不满足
    * hard: [154.寻找旋转排列数组中的最小值Ⅱ](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)
* 使用场景————`单调函数`上找`特定值`


### 三分查找
* 使用场景————`单峰函数`上寻找`极大值`
    * 单峰：先单增再单减
    * 定义域上任取left_mid和right_mid两点比较，判断上升侧还是下降侧
    * left_mid < right_mid：
        * 上升侧，max在中间，在lmid右侧；
        * max在rmid右侧。
    * left_mid > right_mid：
        * 上升侧，max在中间，在lmid左侧；
        * max在rmid右侧。
    * 更快的取值：lmid取二等分点，rmid加小的偏移量。（更快！近似二分查找）
    * 更快的取值：黄金分割点（数学原理）
* 实战
    * [162.寻找峰值](https://leetcode-cn.com/problems/find-peak-element/)
    * [374.猜数字大小](https://leetcode-cn.com/problems/guess-number-higher-or-lower/)
        * 低效算法：挨个猜
        * 高效算法：二分；logN次之后拿到答案
* 求最优解的问题（max / min），可行性问题（true / false）
    * 难度：求最优解的问题 >>> 可行性问题
    * 解空间有单调性：（solution）二分 + 判定，快速求出最优解；在解空间上二分，用判定求解


### 二分答案
* 很有用！！！
* 实战
    * [410.分割数组的最大值](https://leetcode-cn.com/problems/split-array-largest-sum/)
        * C(n-1, m)：暴力搜索，枚举放隔板
        * 求解很难，先看判定
        * 最小化————m个子数组各自和的最大值
        * 判定————m个子数组各自和的最大值 <= T 是否合法
        * 为什么判定用“<=”？解空间分成两半，是单调分段0/1函数
        * T是一个'变量'：`猜一个T（贪心分组，看是否可行，是否符合和<=T，且是否分组组数=m`），判定T是否符合题意
    * [1482.制作m束花所需的最少天数](https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets/)
    * [1011.在D天内送达包裹的能力](https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/)
    * [911.在线选举](https://leetcode-cn.com/problems/online-election/)
    * [875.爱吃香蕉的珂珂](https://leetcode-cn.com/problems/koko-eating-bananas/)




