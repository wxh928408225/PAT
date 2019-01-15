# 1030 完美数列 （25 分）


## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Yue |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：
给定一个正整数数列，和正整数 p，设这个数列中的最大值是 M，最小值是 m，如果 M≤mp，则称这个数列是完美数列。

现在给定参数 p 和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

#### 输入格式：

输入第一行给出两个正整数 N 和 p，其中 N（≤10 **5）是输入的正整数的个数，p（≤10 **9）是给定的参数。第二行给出 N 个正整数，每个数不超过10 **9。
#### 输出格式：
在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

#### 输入样例
```
10 8
2 3 20 4 5 1 6 7 8 9
```
#### 输出样例
```
8
```
## 代码
```c++
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    vector <long long int> array;
    long long int N,p,flag1,flag2;
    scanf("%lld %lld",&N,&p);
    for(long long int i = 0;i<N;i++)
    {
        long long int a;
        scanf("%lld",&a);
        array.push_back(a);
    }
    long long int com=1;
    sort(array.begin(),array.end(),less<long long int>());
    vector <long long int>::iterator iter1,iter2;
    for (iter1 = array.begin(); iter1 != array.end(); iter1++)
        for (iter2 = iter1+com; iter2<array.end();iter2++)
            {
                if (*iter1*p >= *iter2)
                {
                    long long int a = iter2-iter1+1;
                    if (a > com) com = a;
                }
                else
                    break;
            }
    cout << com;
    return 0;
}
```
## 一些需要注意的地方
+ 应该能有分治法去做的
+ 最后一个样例是仅有一个数据时,会出现什么情况
