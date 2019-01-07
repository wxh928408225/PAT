#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
void print(int i,int num);
using namespace std;
int main(int argc, char const *argv[])
{
    int i;
    vector<int> array(10,0);
    for (i=0; i < 10; i++)
    {
        cin >>array.at(i);
    }

    for (i=1; i < 10; i++)
    {
        if (array.at(i) != 0)
            break;
    }
    print(1,i);
    print(array.at(0),0);
    print(array.at(i)-1,i); 
    for (i=i+1;i < 10; i++)
        print(array.at(i),i);
    cout << endl;
    return 0;
}

void print(int i,int num)
{
    while(i>0)
    {
        cout << num;
        i--;
    }
}