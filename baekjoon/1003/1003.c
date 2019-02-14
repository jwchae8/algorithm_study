#include<stdio.h>
int main()
{
    int i, t;
    scanf("%d",&t);
    int one[41];
    int zero[41];
    zero[0] = 1;
    zero[1] = 0;
    one[0] = 0;
    one[1] = 1;
    for(i=2;i<41;i++)
    {
        one[i] = one[i-1]+one[i-2];
        zero[i] = zero[i-1]+zero[i-2];
    }
    for(i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        printf("%d %d\n", zero[n], one[n]);
    }
    return 0;
}
