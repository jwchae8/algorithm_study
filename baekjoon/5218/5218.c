#include<stdio.h>

int main()
{
    int n, i, j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        char a[21], b[21];
        scanf("%s %s", a, b);
        printf("Distances: ");
        for(j=0;j<strlen(a);j++)
        {
            int dst = b[j] - a[j];
            if(dst < 0) dst += 26;
            printf("%d ", dst);
        }
        printf("\n");
    }
    return 0;
}
