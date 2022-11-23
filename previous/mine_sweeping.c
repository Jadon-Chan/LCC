#include <stdio.h>

char test(int, int, char [][102]);

int main(void)
{
    char map[102][102] = {};
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            map[i][j] = getchar();
        getchar();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            map[i][j] = test(i, j, map);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            putchar(map[i][j]);
        putchar('\n');
    } 

    return 0;
}

char test(int i, int j, char (*map)[102])
{
    int count = 0;
    int s, t;

    if (map[i][j] == '*')
        return '*';
    
    for (s = i -1; s <= i + 1; s++)
        for (t = j - 1; t <= j + 1; t++)
            if (!(s == i && t == j))
                if (map[s][t] == '*')
                    count++;
    return '0' + count;
}