#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class office
{
    public: 
    office (int id_p, int d, int c)
    {
        id = id_p;
        d_score = d;
        c_score = c;
        sum_score = d + c;
    }

    int judge(int b, int y)
    {
        if (d_score >= b && c_score >= b)
        {
            if (d_score >= y && c_score >= y)
                return 1;
            if (d_score >= y && c_score < y)
                return 2;
            if (d_score >= c_score)
                return 3;
            return 4;
        }
        return 0;        
    }

    int get_id()
    {
        return id;
    }

    int get_dscore()
    {
        return d_score;
    }
    int get_cscore()
    {
        return c_score;
    }
    int get_sumscore()
    {
        return sum_score;
    }

    void print()
    {
        if (id >9999999)
            printf ("%d %d %d\n",id,d_score,c_score);
        else
        {
            string s(8,'0');
            int l = id;
            for (int i = 7;i>=0;i--)
            {
                s[i] = l % 10 + 48;
                l = l /10;
            }
            cout << s;
            printf (" %d %d\n",d_score,c_score); 
        }
    }


    private:
        int id;
        int d_score;
        int c_score;
        int sum_score;
};

bool cmp(office &s1, office &s2)
{
    if (s1.get_sumscore() != s2.get_sumscore())
        return (s1.get_sumscore() > s2.get_sumscore());
    if (s1.get_dscore() != s2.get_dscore())
        return (s1.get_dscore() > s2.get_dscore());
    return s1.get_id() < s2.get_id();
}

int main(int argc, char const *argv[])
{
    int n, m, h;
    int id, d, c;
    scanf("%d %d %d",&n,&m,&h);
    vector<office> l_1,l_2,l_3,l_4;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d",&id,&d,&c);
        office a(id,d,c);
        int j = a.judge(m,h);
        if (j == 1) l_1.push_back(a);
        if (j == 2) l_2.push_back(a);
        if (j == 3) l_3.push_back(a);
        if (j == 4) l_4.push_back(a);
    }
    cout << l_1.size() + l_2.size() + l_3.size() + l_4.size() <<endl;
    sort(l_1.begin(),l_1.end(),cmp);
    sort(l_2.begin(),l_2.end(),cmp);
    sort(l_3.begin(),l_3.end(),cmp);
    sort(l_4.begin(),l_4.end(),cmp);
    vector<office>::iterator iter;
    for (iter = l_1.begin(); iter != l_1.end(); iter++)
        iter->print();
    for (iter = l_2.begin(); iter != l_2.end(); iter++)
        iter->print();
    for (iter = l_3.begin(); iter != l_3.end(); iter++)
        iter->print();
    for (iter = l_4.begin(); iter != l_4.end(); iter++)
        iter->print();
    return 0;
}