# 1024 科学计数法 (20)

## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Yue |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。

#### 输入格式：

每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。

#### 输出格式：
对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。

#### 输入样例1
```
+1.23400E-03
```
#### 输出样例1
```
0.00123400

```

#### 输入样例2
```
-1.2E+10

```
#### 输出样例2
```
-12000000000

```
## 代码
```c++
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int str2int(string s);
int main(int argc, char const *argv[])
{
    string str;
    int pos_E , num_pow, dec_length;
    cin >> str;
    pos_E = str.find('E');
    string str_int = str.substr(1,pos_E-1);
    dec_length = pos_E - str.find('.') - 1;
    str_int = str_int.erase(str_int.find("."),1);
    string str_pow = str.substr(pos_E+2);
    num_pow = str2int(str_pow);

    if (str.at(pos_E+1) == '-')
    {

        while (num_pow > 1)
        {
            str_int = "0" + str_int;
            num_pow--;
        }   

        str_int = "0." + str_int;
    }
    else
    {
        int sub = num_pow - dec_length;
        if (sub >= 0)
        {
            string a(sub,'0');
            str_int = str_int + a;
        }
        else
        {
            int length_int = str_int.length();
            
            str_int.insert(str_int.begin()+length_int+sub,'.');
        }
    }
    if (str.at(0) == '-')
        str_int = '-' + str_int; 
    cout << str_int << endl;
    
    return 0;
}

int str2int(string s)
{
    int sum = 0;
    for (unsigned int i = 0; i < s.length(); i++)
        sum = sum*10 + s.at(i) - '0';
    return sum;
}

```
## 一些需要注意的地方
+ 这个蛮复杂的，需要讨论好几种情况，还要想到有效位数的问题。
+ 这个例子使用了`string`类的多个方法。
```c++
string a(sub,'0');  //初始化sub个０
str_int.insert(str_int.begin()+length_int+sub,'.');     //在str_int.begin()+length_int+sub位置上插入'.'
pos_E = str.find('E');      //查找E的位置
string str_pow = str.substr(pos_E+2);   // 截取字符串
str_int = str_int.erase(str_int.find("."),1);   //移除str_int.find(".")之后的１个字符
```

