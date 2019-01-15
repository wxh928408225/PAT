# 1029 旧键盘 （20 分）

## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Yue |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

#### 输入格式：

输入在 2 行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过 80 个字符的串，由字母 A-Z（包括大、小写）、数字 0-9、以及下划线 _（代表空格）组成。题目保证 2 个字符串均非空。


#### 输出格式：
按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有 1 个坏键。

#### 输入样例
```
7_This_is_a_test
_hs_s_a_es
```
#### 输出样例
```
7TI
```


## 代码
```c++
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    string a,b;
    vector<char> c;
    cin >> a >> b;
    string::iterator iter;
    for (iter = a.begin(); iter!=a.end(); iter++)
    {
        if (b.find(*iter)==string::npos)
        {
            if (*iter >= 'a' && *iter <= 'z')
                *iter = *iter+'A'-'a';
            if (find(c.begin(),c.end(),*iter)==c.end())
                c.push_back(*iter);
        }
    }

    vector<char>::iterator iter2;
    for(iter2=c.begin(); iter2!=c.end();iter2++)
        cout << *iter2;
    return 0;
}
