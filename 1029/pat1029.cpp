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
