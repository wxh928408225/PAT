# 1018 锤子剪刀布 (20)

## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Yue |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：

大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

#### 输入格式：

输入第1行给出正整数N（<=10^5^），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

#### 输出格式：
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。
#### 输入样例
```
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J

```
#### 输出样例
```
5 3 2
2 3 5
B B
```


## 代码
```c++
#include <cstdio>
#include <map>
#include<iostream>
using namespace std;

struct BCJ
{
    int win = 0;
    int draw = 0;
    int fail = 0;
    int B = 0;
    int C = 0;
    int J = 0;
};

void judge(char a, char b, struct BCJ *c, struct BCJ *d)
{ 
    if (a == 'C' && b == 'C'){
        c->draw++;
        d->draw++;
    }
    if (a == 'B' && b == 'B'){
        c->draw++;
        d->draw++;
    }
    if (a == 'J' && b == 'J'){
        c->draw++;
        d->draw++;
    }
    if (a == 'C' && b == 'B'){
        c->fail++;
        d->win++;
        d->B++;
    }
    if (a == 'C' && b == 'J'){
        c->win++;
        d->fail++;
        c->C++;
    }
    if (a == 'B' && b == 'J'){
        c->fail++;
        d->win++;
        d->J++;
    }
    if (a == 'B' && b == 'C'){
        c->win++;
        d->fail++;
        c->B++;
    }
    if (a == 'J' && b == 'B'){
        c->win++;
        d->fail++;
        c->J++;
    }
    if (a == 'J' && b == 'C'){
        c->fail++;
        d->win++;
        d->C++;
    }
}

char pr(struct BCJ a)
{
    if (a.B >= a.C && a.B >= a.J)
        return 'B';
    if (a.C > a.B && a.C >= a.J)
        return 'C';
    if (a.J > a.B && a.J > a.C)
        return 'J';
}

int main(int argc, char const *argv[])
{
    int i;
    scanf("%d",&i);
    struct BCJ c,d;
    char a,b;
    while(i--)
    {
        cin >> a >> b;
        judge(a,b,&c,&d);
    }
    printf ("%d %d %d\n",c.win,c.draw,c.fail);
    printf ("%d %d %d\n",d.win,d.draw,d.fail);
    printf ("%c %c",pr(c),pr(d));
    return 0;
}
```

