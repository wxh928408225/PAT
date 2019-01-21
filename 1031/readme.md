# 1031 查验身份证 （15 分）

## 题目要求
作者| 单位 | 时间限制 | 内存限制 | 代码长度限制|
-------- | --- | ---| --- | ---- |
CHEN, Yue |PTA联盟 |200ms | 64MB| 16KB

#### 题目内容：
一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：

首先对前17位数字加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；然后将计算的和对11取模得到值Z；最后按照以下关系对应Z值与校验码M的值：
```
Z：0 1 2 3 4 5 6 7 8 9 10
M：1 0 X 9 8 7 6 5 4 3 2
```
现在给定一些身份证号码，请你验证校验码的有效性，并输出有问题的号码。

#### 输入格式：

输入第一行给出正整数N（≤100）是输入的身份证号码的个数。随后N行，每行给出1个18位身份证号码。

#### 输出格式：
按照输入的顺序每行输出1个有问题的身份证号码。这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。如果所有号码都正常，则输出All passed。

#### 输入样例1
```
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
```
#### 输出样例1
```
12010X198901011234
110108196711301866
37070419881216001X
```
#### 输入样例2
```
2
320124198808240056
110108196711301862
```
#### 输出样例2
```
All passed
```

## 代码
```c++
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

int calculate(string m)
{
    int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char z[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
    int sum = 0;
    int test;
    for (int i=0; i<17;i++)
    {
        if (m.at(i) > '9' || m.at(i) < '0')
            return 0;
        int n =  m.at(i) - '0';
        sum = (weight[i]*n)+sum;
        test = sum % 11;
    }
    if (m.at(17) == z[test])
        return 1;
    else 
        return 0;

}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int flag = 0;
    while(n--)
    {
        string id_num;
        cin >> id_num;
        if (calculate(id_num) == 0)
        {
            cout << id_num << endl;
            flag = 1;
        }
    }
    if (!flag)
        cout << "All passed" << endl;
    return 0;
}

```
```python
def calculate(m):
    weights = [7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2]
    L = ['1','0','X','9','8','7','6','5','4','3','2']
    sum = 0
    for i in range(17):
        if m[i] > '9' or m[i] < '0':
            return 0
        n = int(m[i])
        sum = (weights[i] * n) + sum
        test = sum % 11
    if str(m[-1]) == L[test]:
        return 1
    else:
        return 0

n = input()
e = 0
for j in range(n):
    num = raw_input()
    if calculate(num) == 0:
        print(num)
        e = 1
if e == 0:
    print('All passed')

```