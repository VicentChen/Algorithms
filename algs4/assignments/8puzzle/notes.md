# 8puzzle
利用A*算法解决拼图问题

## 思路
 使用优先级队列寻找最短路径
 - 注意这里**一定要用manhattan作为优先级**
 - **在构造方法中计算manhattan和hamming**
 - `compareTo`方法中最好不要调用`manhattan()`和`hamming()`

## 结果
最终结果
```
               filename   insert()         delMin()
---------------------------------------------------
=> FAILED  puzzle29.txt      31096   (1.5x)   18711   (1.5x)
=> FAILED  puzzle34.txt     297357   (1.1x)  142032   (1.1x)
=> passed  puzzle36.txt    1289235           627995         
=> passed  puzzle39.txt     117556            57445         

               filename    Board()            equals()         manhattan()
--------------------------------------------------------------------------
=> FAILED  puzzle29.txt      49804   (1.5x)      49802   (1.5x)      49807         
=> FAILED  puzzle34.txt     439386   (1.1x)     439384   (1.1x)     439389         
=> passed  puzzle36.txt    1917227             1917225             1917230         
=> passed  puzzle39.txt     174998              174996              175001         
```