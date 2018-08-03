# pat 1015 德才论 (25)

## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Li |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：
《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

#### 输入格式：

输入第1行给出3个正整数，分别为：N（<=10^5^），即考生总数；L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。

随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。

#### 输出格式：

输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

#### 输入样例
```
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60

```
#### 输出样例

```
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
```

## 代码
```c++
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class office
{
    public: 
    office (int id_p, int d, int c)
    {
        id = id_p;
        d_score = d;
        c_score = c;
        sum_score = d + c;
    }

    int judge(int b, int y)
    {
        if (d_score >= b && c_score >= b)
        {
            if (d_score >= y && c_score >= y)
                return 1;
            if (d_score >= y && c_score < y)
                return 2;
            if (d_score >= c_score)
                return 3;
            return 4;
        }
        return 0;        
    }

    int get_id()
    {
        return id;
    }

    int get_dscore()
    {
        return d_score;
    }
    int get_cscore()
    {
        return c_score;
    }
    int get_sumscore()
    {
        return sum_score;
    }

    void print()
    {
        if (id >9999999)
            printf ("%d %d %d\n",id,d_score,c_score);
        else
        {
            string s(8,'0');
            int l = id;
            for (int i = 7;i>=0;i--)
            {
                s[i] = l % 10 + 48;
                l = l /10;
            }
            cout << s;
            printf (" %d %d\n",d_score,c_score); 
        }
    }


    private:
        int id;
        int d_score;
        int c_score;
        int sum_score;
};

bool cmp(office &s1, office &s2)
{
    if (s1.get_sumscore() != s2.get_sumscore())
        return (s1.get_sumscore() > s2.get_sumscore());
    if (s1.get_dscore() != s2.get_dscore())
        return (s1.get_dscore() > s2.get_dscore());
    return s1.get_id() < s2.get_id();
}

int main(int argc, char const *argv[])
{
    int n, m, h;
    int id, d, c;
    scanf("%d %d %d",&n,&m,&h);
    vector<office> l_1,l_2,l_3,l_4;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d",&id,&d,&c);
        office a(id,d,c);
        int j = a.judge(m,h);
        if (j == 1) l_1.push_back(a);
        if (j == 2) l_2.push_back(a);
        if (j == 3) l_3.push_back(a);
        if (j == 4) l_4.push_back(a);
    }
    cout << l_1.size() + l_2.size() + l_3.size() + l_4.size() <<endl;
    sort(l_1.begin(),l_1.end(),cmp);
    sort(l_2.begin(),l_2.end(),cmp);
    sort(l_3.begin(),l_3.end(),cmp);
    sort(l_4.begin(),l_4.end(),cmp);
    vector<office>::iterator iter;
    for (iter = l_1.begin(); iter != l_1.end(); iter++)
        iter->print();
    for (iter = l_2.begin(); iter != l_2.end(); iter++)
        iter->print();
    for (iter = l_3.begin(); iter != l_3.end(); iter++)
        iter->print();
    for (iter = l_4.begin(); iter != l_4.end(); iter++)
        iter->print();
    return 0;
}
```
## 一些需要注意的地方
+ 题目有个坑，学生准考证信息如果使用`int`类型描述的话，输出是当位数不足8位时会截断前面的0；我采用的方法是将`int`转化成字符串，然后补足零位输出。
+ 这个题需要注意的是cmp函数的写法，复杂条件下排序需要自定义排序规则。
```c++
bool cmp(office &s1, office &s2)
{
    if (s1.get_sumscore() != s2.get_sumscore())
        return (s1.get_sumscore() > s2.get_sumscore());
    if (s1.get_dscore() != s2.get_dscore())
        return (s1.get_dscore() > s2.get_dscore());
    return s1.get_id() < s2.get_id();
}
```
+ 对于`vector`和`iterator`的写法要注意。
+ 使用`cin`和`cout`貌似会超时。

