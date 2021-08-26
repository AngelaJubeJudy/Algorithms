# Topic Ⅹ-Ⅳ: Bitwise Algorithms

* 效果：提高运行效率
* 十进制与二进制的转换：短除法
    * 二进制转十进制：幂次和

* 位运算符
    * 按位与 &
    * 按位或 |
    * 按位取反 ~
        * 全是1：最大的负数，-1
    * 按位异或 ^（相同得0，不同得1）
    * 左移 <<：0011 --> 0110
        * 若左移后，最高位溢出，不要了；空位补零
    * 右移 >>：0011 --> 0001
        * 逻辑右移：空位补零，多的位置删除
        * 算术右移：除以2向下取整；`空位补符号位`（正数补零，负数补一），多的位置删除

* `异或运算（xor）`
    * 不进位加法
    * x ^ 0 = x
    * x ^ x = 0
        * x ^ x ^ 0 = x ^ x
    * 交换两个数：a = a ^ b, b = a ^ b, a = a ^ b
        * a 存储 a ^ b
        * b 存储 a ^ b = a ^ b ^ b = a
        * a 存储 a ^ b = a ^ a ^ b = b
    * 成对变换：0-1， 2-3， 4-5，...

* `指定位置`的位运算
    * 二进制数的最右边为第0位
    * 【♥】获取x在二进制下的第n位：(x >> n) & 1，右移n位后“AND 1”得到数本身
    * 修改：1左移n位，与目标位运算
        * n位变为1：x | (1<<n)
            * 1 | 1 得 1
            * 0 | 1 得 0
        * n位变为0：x & (~(1<<n))
            * 异或：相同得0，不同得1
            * 用 0& 得0
        * 【♥】n位取反：x ^ (1<<n)
        * x 的最右边第n位清零：x & (~0<<n)
            * 1111..11 左移n位：11100...00
            * 再与运算：后n位清零
        * x 的最高位至第n位（含）清零：x & ((1<<n) - 1)
            * 1111..11 左移n位，减法借位到第n位

* 实战要点
    * 判断`奇偶`
        * 奇：x%2 = 1 --> (x&1) = 1
        * 偶：x%2 = 0 --> (x&1) = 0
    * 除以2的幂次
        * x/2 --> x >> 1
        * 例：mid = (left + right)/2 --> (left + right) >> 1
    * 【♥】`lowbit(x)`
        * 得到最低位的1：x & -x 或 x & (~x + 1)
        * 清零最低位的1：x = x & (x - 1)

* 实战
    * [191.位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)---E
    * [231.2的幂](https://leetcode-cn.com/problems/power-of-two/)---E
    * [190.颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/)---E
    * [338.比特位计数](https://leetcode-cn.com/problems/counting-bits/)---E
    * [50.Pow(x,n)——快速幂](https://leetcode-cn.com/problems/powx-n/)---M
    * [51.N皇后](https://leetcode-cn.com/problems/n-queens/)---H
    * [37.解数独](https://leetcode-cn.com/problems/sudoku-solver/)---H




