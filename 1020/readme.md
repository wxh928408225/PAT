# 1020 月饼 (25)

## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Yue |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：

月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。

#### 输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

#### 输出格式：
对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。
#### 输入样例
```
3 20
18 15 10
75 72 45
```
#### 输出样例
```
94.50
```


## 代码
```c++
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
struct mooncake{
    float number;
    float price;
    float unit_price;
};
bool cmp(struct mooncake &s1, struct mooncake &s2){
    return s1.unit_price > s2.unit_price;
}

int main(int argc, char const *argv[])
{
    int a,k,j;
    float sum = 0,s=0,l=0;
    cin >> a >> k;
    vector<struct mooncake> b(a);
    for (int i=0; i<a; i++)
    {
        float c;
        cin >> c;
        b[i].number = c;
    }
    for (int i=0; i<a; i++)
    {
        float c;
        cin >> c;
        b[i].price = c;
        b[i].unit_price = c / b[i].number;
    }
    sort(b.begin(),b.end(),cmp);
    for (j = 0; s+b[j].number <= k && j<a; j++)
    {
        sum = sum + b[j].price;
        s = s + b[j].number;
    }
    if (j != a)
    {
    sum = sum + (k-s) * b[j].unit_price;
    printf ("%.2f",sum);
    }
    else
    {
        printf ("%.2f",sum);
    }
    return 0;
}

```
## 一些需要注意的地方
+ 这个注意价值最高的月饼是单价最高的。