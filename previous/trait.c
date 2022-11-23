#include <stdio.h>
#include <stdbool.h>

void backward(int *, int *, bool [][52]);

int main(void)
{
    int n, m, x, y;
    char map[52][52] = {};
    bool flag[52][52] = {};
    int count;
    scanf("%d %d %d %d\n", &n, &m, &x, &y);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            map[i][j] = getchar();
            if (map[i][j] == '#')
            {
                count++;
                flag[i][j] = 1;
            }
        }
        getchar();
    }
    printf("%d\n", count);
    for (int i = 1; i <= count; i++)
    {
        printf("%d %d\n", x, y);
        backward(&x, &y, flag);
    }

    return 0;
}
void backward(int * x, int * y, bool flag[52][52])
{
    int s;
    for (s = *x - 1; s <= *x + 1; s += 2)
    {
        if (flag[s][*y])
        {
            flag[*x][*y] = 0;
            *x = s;
            return;
        }
    }
    for (s = *y - 1; s <= *y + 1; s += 2)
    {
        if (flag[*x][s])
        {
            flag[*x][*y] = 0;
            *y = s;
            return;
        }
    }
}