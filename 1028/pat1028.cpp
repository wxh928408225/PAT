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