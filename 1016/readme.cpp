#include <iostream>
#include <string>
using namespace std;
int count(string a, char b)
{
    int i = 0;
    for (int j = 0; j < a.size(); j++)
        if (a[j] == b)
            i = (i*10)+(b-48);
    return i;
}
int main(int argc, char const *argv[])
{
    string a,b;
    char c,d;
    cin >> a >> c >> b >> d;
    cout << count(a,c)+count(b,d);
    return 0;
}
