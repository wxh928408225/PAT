#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int num,sum=1,i=1;
    int line;
    char ch;
    cin >> num >> ch;
    for(;sum<=num;i++)
    {
        sum = sum + (2*i+1) *2;
    }
    sum = sum -(2*(i-1)+1) *2;
    i = i-2;
    for (line=i;line>0;line--)
    {
        for (int k = 0; k < i -line; k++)
            cout<<" ";
        for (int k = 0; k < 2*line+1; k++)
            cout << ch;
        cout << endl;
    }

    for (line=0;line<=i;line++)
    {
        for (int k = 0; k < i -line; k++)
            cout<<" ";
        for (int k = 0; k < 2*line+1; k++)
            cout << ch;
        cout << endl;
    }
    cout << num-sum<<endl;
    return 0;
}
