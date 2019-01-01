# 1021 个位数统计 (15)

## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Yue |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：
给定一个k位整数N = d~k-1~*10^k-1^ + ... + d~1~*10^1^ + d~0~ (0<=d~i~<=9, i=0,...,k-1, d~k-1~>0)，请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。

#### 输入格式：

每个输入包含1个测试用例，即一个不超过1000位的正整数N。

#### 输出格式：
对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。


#### 输入样例
```
100311
```
#### 输出样例
```
0:2
1:3
3:1
```


## 代码
```c++
#include <iostream>
#include <string>
#include <map>
using namespace std;


int main(int argc, char const *argv[])
{
    map<char,int,less<char>>mapnumber;

    string a;
    cin >> a;
    
    string:: iterator iter;

    for (iter=a.begin(); iter!=a.end(); iter++)
    {
        mapnumber[*iter]++;
    }
    
    for (const auto &w: mapnumber)
        cout << w.first <<":"<< w.second<< endl;
    return 0;
}

```
## 一些需要注意的地方
+ 使用了`map`关联容器.
+ 注意`greater`和`less`的使用，还有`map`的输出.

