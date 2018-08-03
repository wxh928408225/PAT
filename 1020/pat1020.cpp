#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
struct mooncake{
    float number;
    float price;
    float unit_price;
};
bool cmp(struct mooncake &s1, struct mooncake &s2){
    return s1.unit_price > s2.unit_price;
}

int main(int argc, char const *argv[])
{
    int a,k,j;
    float sum = 0,s=0,l=0;
    cin >> a >> k;
    vector<struct mooncake> b(a);
    for (int i=0; i<a; i++)
    {
        float c;
        cin >> c;
        b[i].number = c;
    }
    for (int i=0; i<a; i++)
    {
        float c;
        cin >> c;
        b[i].price = c;
        b[i].unit_price = c / b[i].number;
    }
    sort(b.begin(),b.end(),cmp);
    for (j = 0; s+b[j].number <= k && j<a; j++)
    {
        sum = sum + b[j].price;
        s = s + b[j].number;
    }
    if (j != a)
    {
    sum = sum + (k-s) * b[j].unit_price;
    printf ("%.2f",sum);
    }
    else
    {
        printf ("%.2f",sum);
    }
    return 0;
}
