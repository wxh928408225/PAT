#include <iostream>
#include <string>
#include <map>
using namespace std;


int main(int argc, char const *argv[])
{
    map<char,int,less<char>>mapnumber;

    string a;
    cin >> a;
    
    string:: iterator iter;

    for (iter=a.begin(); iter!=a.end(); iter++)
    {
        mapnumber[*iter]++;
    }
    
    for (const auto &w: mapnumber)
        cout << w.first <<":"<< w.second<< endl;
    return 0;
}