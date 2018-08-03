#include <cstdio>
#include <map>
#include<iostream>
using namespace std;

struct BCJ
{
    int win = 0;
    int draw = 0;
    int fail = 0;
    int B = 0;
    int C = 0;
    int J = 0;
};

void judge(char a, char b, struct BCJ *c, struct BCJ *d)
{ 
    if (a == 'C' && b == 'C'){
        c->draw++;
        d->draw++;
    }
    if (a == 'B' && b == 'B'){
        c->draw++;
        d->draw++;
    }
    if (a == 'J' && b == 'J'){
        c->draw++;
        d->draw++;
    }
    if (a == 'C' && b == 'B'){
        c->fail++;
        d->win++;
        d->B++;
    }
    if (a == 'C' && b == 'J'){
        c->win++;
        d->fail++;
        c->C++;
    }
    if (a == 'B' && b == 'J'){
        c->fail++;
        d->win++;
        d->J++;
    }
    if (a == 'B' && b == 'C'){
        c->win++;
        d->fail++;
        c->B++;
    }
    if (a == 'J' && b == 'B'){
        c->win++;
        d->fail++;
        c->J++;
    }
    if (a == 'J' && b == 'C'){
        c->fail++;
        d->win++;
        d->C++;
    }
}

char pr(struct BCJ a)
{
    if (a.B >= a.C && a.B >= a.J)
        return 'B';
    if (a.C > a.B && a.C >= a.J)
        return 'C';
    if (a.J > a.B && a.J > a.C)
        return 'J';
}

int main(int argc, char const *argv[])
{
    int i;
    scanf("%d",&i);
    struct BCJ c,d;
    char a,b;
    while(i--)
    {
        cin >> a >> b;
        judge(a,b,&c,&d);
    }
    printf ("%d %d %d\n",c.win,c.draw,c.fail);
    printf ("%d %d %d\n",d.win,d.draw,d.fail);
    printf ("%c %c",pr(c),pr(d));
    return 0;
}