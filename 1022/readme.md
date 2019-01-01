# 1022 D进制的A+B (20)

## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Yue |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：
输入两个非负10进制整数A和B(<=2^30^-1)，输出A+B的D (1 < D <= 10)进制数。

#### 输入格式：

输入在一行中依次给出3个整数A、B和D。

#### 输出格式：
输出A+B的D进制数。


#### 输入样例
```
123 456 8
```
#### 输出样例
```
1103
```


## 代码
```c++
#include <iostream>
#include <deque>
#include <iterator>
using namespace std;

int main()
{
    int a,b,c,d;
    deque<int> f;
    cin >> a >> b >> d;
    c = a + b;
    
    if (c == 0)
    {
        cout << c << endl;
        return 0;
    }
    while(c){
        f.push_front(c%d);
        c = c/d;
    }
    for (deque<int>::iterator iter = f.begin();iter != f.end(); iter++){
        cout << *iter;
    }
    cout << endl;
    return 0;
}

```
## 一些需要注意的地方
+ 在判断条件处还可以进一步改进.

