# 1017 A除以B (20)

## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Yue |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。
#### 输入格式：

输入在1行中依次给出A和B，中间以1空格分隔。

#### 输出格式：
在1行中依次输出Q和R，中间以1空格分隔。
#### 输入样例
```
123456789050987654321 712345
```
#### 输出样例
```
17636684150141093474 3
```


## 代码
```c++
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string number;
    int b,k,i,d;
    cin >> number >> b;
    int bit = number.length();
    if (bit == 1)
    {
        cout << (number[0]-48) / b << " "  << (number[0]-48) % b;
        return 0;
    }
    if ((int)number[0] < b + 48)
    {
        k = (int(number[0])-48) * 10;
        i = 1;
    }
    else
    {
        k = 0;
        i = 0;
    }
    for (; i < bit; i++)
    {
        k = k + int(number[i])-48;
        cout << (k/b);
        d = k % b;
        k = d * 10;
    }
    cout << " " << k/10;
    return 0;
}

```
## 一些需要注意的地方
+ 其实就是按照插法法则计算就好了。
+ 这个代码写的不怎么美观，感觉需要改进。

