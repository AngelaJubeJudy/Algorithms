# Topic Ⅲ: Hash, Unordered Set

## 哈希
### 哈希表/散列表
* 用关键码 key 直接访问 value；任意 key 
    * 内部：data_structure[hash(key)] = value 
    * 对外：hash_table[key] = value 
* 数据结构：链表、数组 
* 哈希函数: hash()
    * 用来映射复杂信息到较小的值域范围，方便存储和访问。
    * `hash(key)：得到数据结构的索引。`
* 最简单的哈希：count[]稀疏数组，计数；空间复杂度O(n).
* 哈希冲突/哈希碰撞：两个不同 key 算出相同 hash(key)
    * 解决方案一：多开一个数组（浪费空间）。
    * 解决方案二：数组套链表（表头数组每个位置挂一个链表），“`开散列`”；数组存指针/引用，单链表存数据（用于进行`数据比较`）；和“邻接表”类似。
* 工程应用
    * 电话本，用户信息表，LRU Cache，键值对存储（例，Redis）
* 时间复杂度
    * 取决于hash()的实现，最好情况增删改查为O(1)，最坏为O(n)
    * 在各语言中使用库函数时可以认为是O(1).
* `无序`！！！
* 大整数的哈希：可以通过模一个大质数实现。
* 字符串的哈希：看成27进制数。


## 集合与映射
* Set：存储`不重复`元素的数据结构
    * 遍历：按元素大小排列
    * 有序集合：用平衡二叉树实现；时间复杂度O(logn)，实现较难
    * 无序集合：用 hash 实现；TC = O(1)
* Map 映射：存储关键码不重复的键值对。
    * 遍历：按 key 大小排列
    * 有序集合：用平衡二叉树实现；时间复杂度O(logn)，实现较难
    * 无序集合：用 hash table 实现；TC = O(1)
* 各语言的实现
    * C++: set / map 有序，unordered_set / unordered_map 无序；无需判断有没有；不存在时会返回尾部.end()，则判断元素时`不等于尾部`就是存在！！！
    * JAVA: Set，Map；先判断（用contains(key)很快；contains(value)很慢，不建议用！），才能操作。
    * Python: list，字典

* 实战
    * [1.两数之和](https://leetcode-cn.com/problems/two-sum/)
        * 思路：枚举一个数x，看之前有没有 target - x 的映射。
    * [874.模拟行走机器人](https://leetcode-cn.com/problems/walking-robot-simulation/)
        * 思路：暴力
        * 思考点：判断障碍物（将obstacles[]数组映射为一个集合）；判断方向
        * 对二元组坐标哈希：方案一，存String，“-200,30000”；方案二，看成进制数，-200*30000+30000，平移后（30000-200）*30000+30000+30000，效率更高
        * 两个数组dx和dy用来`定义方向`：北（dx=0, dy=1），南（dx=0, dy=-1）,东（dx=1, dy=0）,西（dx=-1, dy=0）
    * [49.字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/) 
        * 思路：每个字符串内的字符按同样的顺序排序，再分组（用hash map）
        * 方案一, map<String, Group>：每个字符串中字母排序，排序后的字符串作为hash map的key。
        * 方案二, map<array[26], Group>:统计每个字符串中字母出现次数，把长度为26的计数数组作为key。
    * 实战：[30.串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/)
        * 思路：找子串（枚举）；单词顺序无所谓；字符串先分成若干个单词，单词排序，看与words数组是否一样。
        * 实现：每个单词的出现次数放进哈希表，两个hash_map的比较看是否相同。先算words数组的哈希映射。两个hash_map互为子map，则相同。
    * 实战：实现一个Map


## 经典实现：LRU (Least Recently Used)
* 实战：[146.LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/)
* 缓存的两个要素：大小，替换策略
    * 什么内容留在缓存，
    * 什么内容需要被替换
    * LRU / LFU（Least Frequently Used；实现:平衡二叉树or堆）
* 思路：`链表`支持在中间快速删除（命中的内容），双向链表用于按时间顺序保存数据；常数时间快速访问、更新、删除使用`哈希`建立的映射。
* 高频必考题！！！


