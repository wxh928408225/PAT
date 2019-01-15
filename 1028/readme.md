# 1028 人口普查 （20 分）

## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Yue |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：
某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过 200 岁的老人，而今天是 2014 年 9 月 6 日，所以超过 200 岁的生日和未出生的生日都是不合理的，应该被过滤掉。

#### 输入格式：

输入在第一行给出正整数 N，取值在(0,10**5);随后 N 行，每行给出 1 个人的姓名（由不超过 5 个英文字母组成的字符串）、以及按 yyyy/mm/dd（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。
#### 输出格式：
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

#### 输入样例
```
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
```
#### 输出样例
```
3 Tom John

```


## 代码
```c++
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int cal(int year,int month,int day);
int num = 0;

int main(int argc, char const *argv[])
{
    int a;
    scanf("%d",&a);
    string old,young,name;
    int year,month,day;
    int max=0;
    int min=9999999999999;
    
    while(a--)
    {
        cin >> name;
        scanf("%4d/%2d/%2d",&year,&month,&day);
        int k = cal(year,month,day);
        if (k == 0) continue;
        if (k>max)
        {
            max = k;
            young = name;
        }
        if (k<min)
        {
            min = k;
            old = name;
        }
    }
    if (num !=0 )
        cout << num << " " << old << " " << young << endl;
    else
        cout << num;
    return 0;
}

int cal(int year,int month,int day)
{
    int a = year*365+month*30+day;
    if (a>=1814*365+9*30+6 && a<=2014*365+9*30+6)
    {
        num++;
        return a;
    }
    else return 0;
}
```
## 一些需要注意的地方
+ 当没有符合的人时,只需要输出0

