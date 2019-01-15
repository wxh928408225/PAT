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