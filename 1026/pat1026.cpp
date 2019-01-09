#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
    int c1, c2;
    cin >> c1 >> c2;
    int time = (c2-c1+50)/100;
    int hours = time /3600;
    int minutes = time%3600/60;
    int second = time%60;
    printf("%02d:%02d:%02d\n",hours,minutes,second);
    return 0;
}
