# Percolation
通过并查集判断系统是否为渗透系统，即从顶部可以到达底部
<figure class="half">
    <img src="imgs/percolates-no.png" width="300"/>
    <img src="imgs/percolates-no.png" width="300"/>
</figure>

## 思路
 -  使用课程上提到的`Virtual Top`跟`Virtual Bottom`即可，能够将判断系统是否渗透的时间从平方量级缩短为常数量级
 - **backwash问题：** 如下图，直接使用上面描述方法会使`isFull`判断出错（但不会影响统计）
 ![backwash](imgs/percolation-backwash.png)
 - backwash解决方法是**不使用Virtual Bottom, 并添加一个额外的help数组**，help数组中保存当前节点是否与底部连通。每次`Union`前判断要连接的两个节点中是否有一个与底部连通，若有则将`Union`后的root设置为与底部连通。
 - backwash的另一个解决方法为多使用一个`WeightedUnionFind`，并且在多余的`WeightedUnionFind`中不使用Virtual Bottom。但是这种做法带来的内存消耗会导致bonus丢失

## 参考资料

 1. [Coursera Discuss][1]
 2. [Algorithms, Princeton, Coursera课程整理与回顾][2]

 [1]: https://www.coursera.org/learn/algorithms-part1/programming/Lhp5z/percolation/discussions/threads/FJ_wJQuCEeisShJkjHvBCA
 [2]: https://segmentfault.com/a/1190000005345079