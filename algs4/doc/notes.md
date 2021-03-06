# Algorithms

## 1 Fundamentals

### 1.1 Programming Model

 - Java中原始数据类型：`int`(整数)，`double`(实数)，`boolean`(布尔型)，`char`(字符)
 - 程序源代码的组成：原始类型、标识符、变量、操作符、常量、表达式

### 1.3 Stacks and Queues

#### 栈：LIFO，push，pop
 - 变容栈：满->容量翻倍；1/4->容量减半 (可以避免抖动)
 - 链表实现：能够保证常数时间的操作，但相对于数组较慢，使用的空间更多
 - 数组实现：总体速度更快，但是某些操作会导致大量内存访问，响应时间变长；resize只会被调用logN次

 - 队列：FIFO，enqueue，dequeue


### 1.5 Union-Find(并查集)

#### 思想
 - **懒计算：** 将计算工作尽可能后移

#### API

```
/* API of class UnionFind */ 

void union(int p, int q); // 连接节点p和节点q
int find(int p); // p所在连通分量的标识符
boolean connected(int p, int q); // 判断p和q是否处于同一连通分量
int count(); // 计算连通分量的数量
```

 - 并查集可用于解决连通性问题

#### Quick-Find
复杂度为$N^2$
  1. 起始：各个节点为独立的连通分量
  2. Union: 连接时修改所有相同连通分量标识符
  3. Find: 直接比较连通分量标识符

#### Quick-Union
复杂度为$N^2$
  1. 起始：各个节点为独立的连通分量
  2. Union: 直接连接两个节点
  3. Find: 找到根节点再进行比较

##### 加权Quick-Union
  与Quick-Union类似，在Union的时候将规模较小的树连接到规模较大的树上

#### Union-Find
 路径压缩，将子节点指向父节点的父节点

## 2 Sorting
**成本模型：比较和交换的次数**

### 2.1 Elementary Sorts

 - 回调：**将函数或方法的指针作为参数传入**

#### 选择排序
 - 时间复杂度: $O(\frac{N^2}{2})$

#### 插入排序
 - 时间复杂度: $O(\frac{N^2}{4})$次交换和比较

**<span style="color: #4169E1;">对于基本有序的数据，插入排序会更快，只需要遍历数组一遍即可，但是冒泡排序即使使用了提前终止标识，也需要多遍历一次以确认已经有序</span>**

#### 希尔排序
 - **思想：**插入排序一次只能移动一位，即使已知要移动很远的距离。如果增量大，要排序的数组长度就小，算法性能好；如果增量小，基于前面已经排好序的数组，使用插入排序能够获取良好的性能。
 - 时间复杂度: $O(N^{1.5})$

#### 洗牌
 - **思想：**随机数排序($O(NlogN)$ / $O(N^2)$)
 - **思想：**每次输入与已输入卡组进行交换

### 2.2 Merage Sort
 - 时间复杂度: $O(NlogN)$
 - 空间复杂度: $O(N)$)(辅助数组)

**思想：分冶法，一次解决两个小问题，然后合并**

#### 自顶向下
 - $O(\frac{NlogN}{2} - NlogN)$次比较
 - $O(\frac{NlogN}{6})$次数组访问
 
 - 优化：对小数组使用插入排序、数组已经有序直接归并、交换原数组和辅助数组

#### 自底向上
 - $O(\frac{NlogN}{2} - NlogN)$次比较

#### assert
 - 在程序最后加入`assert`表明方法的作用 

#### 稳定性
 - **值相同时相对顺序被保留**
 - **稳定排序：**插入排序、归并排序、冒泡排序
 - **非稳定排序：**选择排序、希尔排序

### 2.3 Quick Sort

**Quick Sort比Merage Sort快**

#### 步骤
 1. 数组洗牌
 2. 双向查找第一个元素的位置
 3. 比较新增的两个子数组

#### 优化
 - 小数组使用插入排序
 - 三取样切分

#### Quick Select
 - 依据快速排序第`k`个元素在合适的位置的特性，找出第`k`大的元素 - ($O(N)$)

### 2.4 Priority Queues
 优先队列：支持删除最大元素和插入元素的是数据类型

#### API
 - 存储最大的n个数用小顶堆实现
 - 寻找最大n个数时间复杂度 $O(NlogM)$

#### 二叉堆
 - **维持堆有序**
```
void swim(int k) {                |  void sink(int k) {
  while(k > 1 && less(k/2, k)) {  |    while(2 * k <= N) {
    exch(k/2, k);                 |      int j = 2 * k;
    k /= 2;                       |      if (j < N  && less(j, j + 1)) j++;
  }                               |      if (!less(k, j)) break;
}                                 |      exch(k, j);
                                  |      k = j;
                                  |   }
                                  |  }
```
#### 堆排序
 - 利用堆的特性，每次删除堆顶的元素，最后可得有序的数组
 - **从数组中构建堆只需要线性时间**
 - 堆排序保证$NlogN$复杂度
 - **缺点：**不稳定、Cache命中率低、

## 3 Searching

### 3.1 Elementary Symbol Tables
符号表：将值关联于一个键上

#### 操作
 - 删除： **延时删除**、**即时删除**

### 3.2 Binary Search Tree
 - **经过多次插入、删除后可能变得不对称**

### 3.3 Balanced Search Trees

#### 2-3树
**完美平衡的2-3树所有null节点到根节点的距离相等**

#### 红黑树 
 - 插入：左黑右红左旋，连续左红右旋，左红右红颜色转换
 - **flipping color:** `root`记得设为红色