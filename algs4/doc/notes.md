# Algorithms

## 1 Fundamentals

### 1.1 Programming Model

 - Java中原始数据类型：`int`(整数)，`double`(实数)，`boolean`(布尔型)，`char`(字符)
 - 程序源代码的组成：原始类型、标识符、变量、操作符、常量、表达式

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
