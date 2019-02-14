#include<stdio.h>

int main()
{
    int i, start, stop, badness, order = 1;
    int diff[1000001];
    int sum = 1, num = 2;
    for(i=2;i<=1000000;i++)
    {
        diff[i] = i-1;
    }
    for(i=2;i<=500000;i++)
    {
        while(i*num<=1000000)
        {
            diff[i*num] = diff[i*num]-i;
            num++;
        }
        num=2;
    }
    scanf("%d %d %d",&start,&stop,&badness);
    while(!(start==0&&stop==0&&badness==0))
    {
        int count = 0;
        for(i=start;i<=stop;i++)
        {
            if(diff[i] >=0 && diff[i] <= badness)count++;
            else if(diff[i] < 0 && diff[i] >=  -badness)count++;
        }
        printf("Test %d: %d\n",order,count);
        scanf("%d %d %d",&start,&stop,&badness);
        order ++;
    }
    return 0;
}
