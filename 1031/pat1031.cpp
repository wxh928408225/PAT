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
    // string a;
    // cin >> a;
    // int i = calculate(a);
    // cout << i << endl;;
}
