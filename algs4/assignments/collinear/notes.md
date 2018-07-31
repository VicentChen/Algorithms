# Collinear
找出所有由4个或以上的点组成的直线

## 存储
 - `BruteCollinearPoints`中线段的条数不会超过点的个数
 - `FastCollinearPoints`中线段的条数不确定，需要用可变容数组实现
 - 整个项目中对内存的限制基本没有，可以放心进行使用

## 排序
 - `Arrays.sort()`采用了`TimSort`，是一种稳定的排序方式。

## 步骤
### Brute Force

**流程：**直接对输入进行暴力四层循环
**points去重：**二层暴力循环即可，在$N^4$面前二层循环开销还是不大的
**提前终止：**提前跳出循环能够减少运行时间，发现斜率不一致的时候可以直接continue，另外，使用局部变量保存运算结果也能减少运算的次数。譬如按`w->x->y->z`的方式进行循环，计算`w`与`x`的斜率后可以进行保存，在下面`y->z`的循环中便可以减少$N^2$此计算

### Fast

**空间换时间，多使用辅助的数据结构和数组**

**流程：**

1. 复制一个数组并排序，获得`sortedPoints` - ($O(NlogN)$)
2. 构建`FastSlope`数组，保存当前点与所有点的斜率，以及当前点在`sortedPoints`中的下标`index` - ($O(N)$)
3. 对`FastSlope`数组依据斜率进行排序 - ($O(NlogN)$)
4. 遍历`FastSlope`数组，找出斜率相同的**3个或以上**的点的`index`(还有一个默认的点是`FastSlope[0]`) - ($O(N)$)
5. 找到线段后，根据`index`字段就可以直接找出两个端点索引`beginIndex`和`endIndex`了
6. 检查标记数组`saveFlag[beginIndex][endIndex]`是否为`true`，意思是该端点是否已经被记录过了，如果有，继续循环，否则将端点记录在`endPoints`数组中
7. 根据`endPoints`数组构建线段 - ($O(N?)$)

**优化：**
 - 与Brute Force不同，去points重放在排序后进行复杂度可降为线性级别
 - 使用一个`slopes`数组保存斜率斜率的计算最多需要进行`\frac{N^2}{2}`次，因为`points[i]-points[j]`与`points[j]-points[i]`的斜率是一样的。另外，让循环只循环至`points.length-4`能够减少3次的循环
 - 在segments去重的时候使用二维布尔数组可以让去重时间化为常数级别

## 注意事项
 - 不要对输入的`points`数组做任何改变