#include <cstdio>
#include <cmath>

int main(int argc, char const *argv[])
{
    int a;
    float f = 0;
    scanf("%d",&a);
    while(a--)
    {
        int c,d;
        scanf("%d %d",&c,&d);
        float e = sqrt(c*c + d*d);
        if (f < e) f = e;
    }
    printf("%.2f",f);
    return 0;
}
