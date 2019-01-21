# 1032 挖掘机技术哪家强 （20 分）

## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Yue |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：
为了用事实说明挖掘机技术到底哪家强，PAT 组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。

#### 输入格式：
输入在第 1 行给出不超过 10**5的正整数 N，即参赛人数。随后 N 行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从1开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。

#### 输出格式：
在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。

#### 输入样例
```
6
3 65
2 80
1 100
2 70
3 40
3 0
```
#### 输出样例
```
2 150
```


## 代码
```c++
#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int k;
    int max_school,max_num;
    cin >> k;
    max_num=max_school=0;
    map<int,int> score;
    while (k--)
    {
        int a,b;
        cin >> a >> b;
        auto iter = score.find(a);
        if (iter==score.end())
        {
            score.insert(pair<int,int>(a,b));
        }
        else
        {
            iter->second += b;
        }
    } 
    map<int,int>::iterator iter = score.begin();
    for (;iter!=score.end();iter++)
    {
        if (iter->second > max_num)
        {
            max_num = iter->second;
            max_school = iter->first;
        }
    }

    cout << max_school << " " << max_num << endl;
    return 0;
}


```
## 一些需要注意的地方
+ 