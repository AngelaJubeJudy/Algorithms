# Topic Ⅶ: Sorting

## 基于比较的各类排序算法
* 排序算法分类
    * 基于比较
    * 非比较类
* 基于比较
    * 初级：
        * 选择排序（选哪一个放到新序列中）：从未排序中选min，放在已排序序列末尾。原地排序，交换位置。
        * 插入排序（摸张牌放哪）：从前往后依次遍历每个未排序，在已排序中找到合适位置插入。数组的插入TC = O(N).
        * 冒泡排序：逆序，则交换。不断循环扫描，TC = O(N^2).
    * 堆排序：基于选择。
        * 优化：从未排序中选min，快速通过 priority queue 找到min（C++中是大根堆，则存负值，弹出原数组中最小的数）
        * 简洁实现：TC = O(NlogN).
        * 有更快的建堆方法
    * 希尔排序：基于插入。
        * 每个小组插入排序；下一次增量减半，继续对每组插入排序。
        * 有序：插入排序越快！
        * 数组乱：分小组提高效率；大组时数组已经相对有序了。
    * 归并排序：基于分治，TC = O(NlogN)；logN层，每层N个数merge.
        * 先递归，再处理本层逻辑。
    * `快速排序`（背诵模板！！！）：基于交换，基于分治。随机选pivot元素。
        * 先让大分块相对有序，左<=右；
        * 内部的无序：递归。
        * 先处理本层逻辑，再递归。
        * pivot选得不好，算法退化；随机选取，期望O(NlogN)
        * `适当swap，实现原地排序`。Hoare Partition经典高效调配
        * Hoare Partition：左想去右，右想去左，或者左右指针相遇，则swap，无序额外空间。
        * 较少拷贝，省空间。
    * 排序的稳定性
        * 不稳定：快排，希尔，选择，堆排序
    * 基于比较的排序：最快优化到O(NlogN)
* 非比较类
    * 计数排序：有确定范围。开额外数组，存储计数；重新回填到原数组。
        * 稳定：拉链，原序扫描遍历、原序回填。
    * 桶排序
    * 基数排序：数值很大时，从低位到高位分别计数排序；过程中保证相对顺序。

## 实战
* [排序数组](https://leetcode-cn.com/problems/sort-an-array/)
* [1122.数组的相对顺序](https://leetcode-cn.com/problems/relative-sort-array/)
* [合并区间](https://leetcode-cn.com/problems/merge-intervals/)
* [数组中的第K大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)
* [货仓选址](https://www.acwing.com/problem/content/description/106/)
    * 数轴：A_1 ~ A_n
    * 建在`中位数`上比较好，奇数商店返回A_(n+1/2)，偶数商店返回A_(n/2)或A_(n+1/2)

* [翻转对](https://leetcode-cn.com/problems/reverse-pairs/)
    * “分治”模板：`二元组+两个条件`的问题
* [区间和的个数](https://leetcode-cn.com/problems/count-of-range-sum/)

