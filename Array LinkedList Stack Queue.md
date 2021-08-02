# Topic Ⅰ: Array, LinkedList, Stack, Queue
## Array 数组
* 特点：连续存储，随机访问——O(1)
* 关键：索引（连续存储空间，快速寻址），寻址
* 操作
    * 查询：TC = O(1)
    * 插入：TC = O(n)
    * 删除：TC = O(n)
    * append (push back): TC = O(1)
    * prepend (push front): TC = O(n)

### Resizable Array 变长数组
* 大小动态变化
    * C++: vector
    * JAVA: ArrayList
    * Python: list
* 3个实现相关问题：`多长？扩容？回收？`
    * 初始：空数组，默认分配常数空间。
    * 空间不够——push back：申请2倍大小空间，数据拷贝到新空间，释放旧空间。
    * 空间利用率不高——pop back：空间利用率不足25%，释放50%当前空间。
    * 扩容两倍：均摊 TC=O(1)
    * 若释放阈值设置为50%：时间复杂度将退化到O(n)。

### 实战
* [88.合并有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)
* [26.去重](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)
* [283.移动零](https://leetcode-cn.com/problems/move-zeroes/)


## LinkedList 链表
### Linked List 单链表
* 特点：不连续内存空间
* `空链表：next = null，需要预判`！！！
    * 解决方案：加一个`保护结点 Head`，其指针指向头节点，其 value 为空；另一个`保护结点 Tail`，其指针指向 null 节点，其 value 为空。
* 操作
    * 插入：TC = O(1)；两次操作，先保留new_node.next=node.next，再保留node.next=new_node.next
    * 删除：node.next=target.next，TC = O(1)；target 为被删节点。
    * 访问：TC = O(n).
    * append (push back): TC = O(1).
    * prepend (push front): TC = O(1).

### Double Linked List
* 2 pointers: next, pre
* “哨兵”
    * (`HEAD`) value=N/A, next=TAIL, pre=null
    * (`TAIL`) value=N/A, next=null, pre=HEAD

### 实战
* [206.反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)
* [25.K个一组反转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)
* [邻值查找](https://www.acwing.com/problem/content/description/138/)
* [141.环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)
* [142.环形链表Ⅱ](https://leetcode-cn.com/problems/linked-list-cycle-ii/)


## Stack 栈
* LIFO
* 操作
    * push: TC = O(1).
    * pop: TC = O(1).
    * 访问: TC = O(1).

## Queue 队列
* FIFO
* 操作
    * push: 从尾入队，TC = O(1).
    * pop：从头出队，TC = O(1).
    * 访问: TC = O(1).
* 变形：
    * `双端队列 (Deque)`，头尾都可以出入；以优先级顺序取出元素
        * 操作
            * 头/尾 push
            * 头/尾 pop
    * `优先队列 (prority queue)`：用堆实现。
        * 操作：按优先级
            * 访问 max/min: TC = O(1).
            * 插入: TC = O(logn).
        * 多种实现方式：二叉堆，二叉平衡树等
* 实战
    * 前缀最小值——额外栈存储前缀的min
    * 各种语言的实现
        * C++ 参考：cppreference
            * 实现：stack, queue, deque, priority_queue
        * JAVA 参考: 菜鸟教程
            * 实现：Stack, PriorityQueue；Queue 和 Deque 可以用 LinkedList。
        * Python：栈、队列、双端队列可以用list实现，优先队列可以用heapq库。
    * [20.有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)
    * [155.最小栈](https://leetcode-cn.com/problems/min-stack/)

## 写一个计算器
### 表达式求值
* 前缀表达式：op A B 
* 后缀表达式： A B op 
* 中缀表达式：3*（1+2）由括号判定执行的优先级
* 每个符号只跟`最近`（因此可以用stack实现）的数字相关
* 实战
    * [150.逆波兰表达式/后缀表达式求值](https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/)
    * [中缀表达式求值](https://leetcode-cn.com/problems/basic-calculator/)
    * [21.合并有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)
    * [66.加一](https://leetcode-cn.com/problems/plus-one/)
    * [641.设计循环双端队列](https://leetcode-cn.com/problems/design-circular-deque/)


