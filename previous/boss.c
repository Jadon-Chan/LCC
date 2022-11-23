#include <stdio.h>
static int boss[1000];

int find(int x)
{
    if (x == boss[x]) 
        return x;   // 如果x的boss是x， 那么x的boss是x
    else
        return find(boss[x]); // 如果x的boss不是x， 那么x的boss是x的boss的boss
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &boss[i]);
    for (int i = 1; i <= n; i++)
        printf("%d ", find(i));

    return 0;
}