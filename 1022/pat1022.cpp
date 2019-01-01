#include <iostream>
#include <deque>
#include <iterator>
using namespace std;

int main()
{
    int a,b,c,d;
    deque<int> f;
    cin >> a >> b >> d;
    c = a + b;
    
    if (c == 0)
    {
        cout << c << endl;
        return 0;
    }
    while(c){
        f.push_front(c%d);
        c = c/d;
    }
    for (deque<int>::iterator iter = f.begin();iter != f.end(); iter++){
        cout << *iter;
    }
    cout << endl;
    return 0;
}