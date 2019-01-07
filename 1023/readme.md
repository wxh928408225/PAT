# 1023 组个最小数 (20)

## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Yue |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：
给定数字0-9各若干个。你可以以任意顺序排列这些数字，但必须全部使用。目标是使得最后得到的数尽可能小（注意0不能做首位）。例如：给定两个0，两个1，三个5，一个8，我们得到的最小的数就是10015558。

现给定数字，请编写程序输出能够组成的最小的数。

#### 输入格式：

输入在一行中依次给出3个整数A、B和D。每个输入包含1个测试用例。每个测试用例在一行中给出10个非负整数，顺序表示我们拥有数字0、数字1、……数字9的个数。整数间用一个空格分隔。10个数字的总个数不超过50，且至少拥有1个非0的数字。



#### 输出格式：
在一行中输出能够组成的最小的数。


#### 输入样例
```
2 2 0 0 0 3 0 0 1 0
```
#### 输出样例
```
10015558

```


## 代码
```c++
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
void print(int i,int num);
using namespace std;
int main(int argc, char const *argv[])
{
    int i;
    vector<int> array(10,0);
    for (i=0; i < 10; i++)
    {
        cin >>array.at(i);
    }

    for (i=1; i < 10; i++)
    {
        if (array.at(i) != 0)
            break;
    }
    print(1,i);
    print(array.at(0),0);
    print(array.at(i)-1,i); 
    for (i=i+1;i < 10; i++)
        print(array.at(i),i);
    cout << endl;
    return 0;
}

void print(int i,int num)
{
    while(i>0)
    {
        cout << num;
        i--;
    }
}

```