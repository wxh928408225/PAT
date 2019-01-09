# 1027 打印沙漏 （20 分）

## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Yue |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

```
*****
 ***
  *
 ***
*****
```
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。
#### 输入格式：

输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。


#### 输出格式：
首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。


#### 输入样例
```
19 *
```
#### 输出样例
```
*****
 ***
  *
 ***
*****
2

```


## 代码
```c++
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int num,sum=1,i=1;
    int line;
    char ch;
    cin >> num >> ch;
    for(;sum<=num;i++)
    {
        sum = sum + (2*i+1) *2;
    }
    sum = sum -(2*(i-1)+1) *2;
    i = i-2;
    for (line=i;line>0;line--)
    {
        for (int k = 0; k < i -line; k++)
            cout<<" ";
        for (int k = 0; k < 2*line+1; k++)
            cout << ch;
        cout << endl;
    }

    for (line=0;line<=i;line++)
    {
        for (int k = 0; k < i -line; k++)
            cout<<" ";
        for (int k = 0; k < 2*line+1; k++)
            cout << ch;
        cout << endl;
    }
    cout << num-sum<<endl;
    return 0;
}
```
