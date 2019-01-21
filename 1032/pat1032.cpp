#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int k;
    int max_school,max_num;
    cin >> k;
    max_num=max_school=0;
    map<int,int> score;
    while (k--)
    {
        int a,b;
        cin >> a >> b;
        auto iter = score.find(a);
        if (iter==score.end())
        {
            score.insert(pair<int,int>(a,b));
        }
        else
        {
            iter->second += b;
        }
    } 
    map<int,int>::iterator iter = score.begin();
    for (;iter!=score.end();iter++)
    {
        if (iter->second > max_num)
        {
            max_num = iter->second;
            max_school = iter->first;
        }
    }

    cout << max_school << " " << max_num << endl;
    return 0;
}
