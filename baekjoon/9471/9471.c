#include<stdio.h>

int get_period(int n)
{
    int a = 0;
    int b = 1;
    int period = 1;
    while(1)
    {
        int next = (a+b)%n;
        a = b;
        b = next;
        if(a == 0 && b == 1)
            break;
        period++;
    }
    return period;
}
long long get_lcm(int x, int y)
{
    int gcd;
    int prod = x*y;
    while(!(x == 0 || y == 0))
    {
        if(x>y) x -= y;
        else y -= x;
    }
    if(x==0)gcd = y;
    else gcd = x;
    return prod/gcd;
}
int main()
{
    int i, j, n;
    int factor[10];
    long long period[10];
    long long result;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int order, mod;
        scanf("%d %d",&order,&mod);
        int num=2, fact_count=0, added = 0;
        factor[0] = 1;
        while(mod!=1)
        {
            if(mod%num == 0)
            {
                mod /= num;
                factor[fact_count] *= num;
                added=1;
            }
            else
            {
                num++;
                if(added)fact_count += 1;
                factor[fact_count] = 1;
                added = 0;
            }
        }
        for(j=0; j<=fact_count; j++)
        {
            period[j] = get_period(factor[j]);
        }
        for(j=0; j<fact_count;j++)
        {
            period[j+1] = get_lcm(period[j],period[j+1]);
        }
        result = period[fact_count];
        printf("%d %lld\n",order,result);
    }
    return 0;
}
