#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string number;
    int b,k,i,d;
    cin >> number >> b;
    int bit = number.length();
    if (bit == 1)
    {
        cout << (number[0]-48) / b << " "  << (number[0]-48) % b;
        return 0;
    }
    if ((int)number[0] < b + 48)
    {
        k = (int(number[0])-48) * 10;
        i = 1;
    }
    else
    {
        k = 0;
        i = 0;
    }
    for (; i < bit; i++)
    {
        k = k + int(number[i])-48;
        cout << (k/b);
        d = k % b;
        k = d * 10;
    }

    cout << " " << k/10;
    
    return 0;
}
