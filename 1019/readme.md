# 1019 数字黑洞 (20)

## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Yue |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：

给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089\ 9810 - 0189 = 9621\ 9621 - 1269 = 8352\ 8532 - 2358 = 6174\ 7641 - 1467 = 6174\ ... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。

#### 输入格式：

输入给出一个(0, 10000)区间内的正整数N。


#### 输出格式：
如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。

#### 输入样例1
```
6767
```
#### 输出样例1
```
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
```

#### 输入样例2
```
2222
```
#### 输出样例2
```
2222 - 2222 = 0000
```

## 代码
```c++
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

void num_list(int c,char st3[]);
struct rule1
{
	bool operator () (const int &a1,const int &a2)
	{
		return a1 > a2;
	}
};
struct rule2
{
	bool operator () (const char &a1,const char &a2)
	{
		return a1 < a2;
	}
};
int main(int argc, char const *argv[])
{
	int y;
	char st1[6],st2[6],st3[6];
	cin >> y;
	num_list(y,st1);
	if (st1[1]==st1[0] && st1[1]==st1[2] && st1[3]==st1[2])
		cout<<st1<<" - "<<st1<<" = 0000"<<endl;
	else
	{
	    while (strcmp(st3, "6174"))
	    {
        strcpy(st2, st1);
        int a,b,c;
        a = atoi(st2);
        sort(st1+0,st1+4,rule1());
        sort(st2+0,st2+4,rule2());
        a = atoi(st1);
        b = atoi(st2);
        c = a-b;
        num_list(c,st3);
        cout<<st1<<" - "<<st2<<" = "<<st3<<endl;;
        strcpy(st1, st3);
	    }
	}
}
void num_list(int c,char st3[])
{
	int i = 4;
	for (int j=0;j<4;j++)
	{
		st3[j] = '0';
	}
	while (c != 0)
	{
		i--;	
		st3[i] = (c % 10)+'0';
		c/=10;	
	}
	st3[4] = '\0';
}
```
