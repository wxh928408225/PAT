#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

void num_list(int c,char st3[]);
struct rule1
{
	bool operator () (const int &a1,const int &a2)
	{
		return a1 > a2;
	}
};
struct rule2
{
	bool operator () (const char &a1,const char &a2)
	{
		return a1 < a2;
	}
};
int main(int argc, char const *argv[])
{
	int y;
	char st1[6],st2[6],st3[6];
	cin >> y;
	num_list(y,st1);
	if (st1[1]==st1[0] && st1[1]==st1[2] && st1[3]==st1[2])
		cout<<st1<<" - "<<st1<<" = 0000"<<endl;
	else
	{
	    while (strcmp(st3, "6174"))
	    {
        strcpy(st2, st1);
        int a,b,c;
        a = atoi(st2);
        sort(st1+0,st1+4,rule1());
        sort(st2+0,st2+4,rule2());
        a = atoi(st1);
        b = atoi(st2);
        c = a-b;
        num_list(c,st3);
        cout<<st1<<" - "<<st2<<" = "<<st3<<endl;;
        strcpy(st1, st3);
	    }
	}
}
void num_list(int c,char st3[])
{
	int i = 4;
	for (int j=0;j<4;j++)
	{
		st3[j] = '0';
	}
	while (c != 0)
	{
		i--;	
		st3[i] = (c % 10)+'0';
		c/=10;	
	}
	st3[4] = '\0';
}