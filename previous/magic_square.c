#include <stdio.h>
static int fill = 1;
static int mat[100][100];
static int n;
static int count;
void magic(int x, int y)
{
    mat[x][y] = fill++;
    count++;
    if (count == n * n)
        return;
    int x1, y1;
    if (x*y != 0)
    {
        x1 = x - 1;
        y1 = y - 1;
    }
    else if (x + y == 0)
    {
        x1 = n - 1;
        y1 = n - 1;
    }
    else if (x == 0)
    {
        x1 = n - 1;
        y1 = y - 1;
    }
    else
    {
        x1 = x - 1;
        y1 = n - 1;
    }
    if (mat[x1][y1])
        magic(x + 1, y);
    else
        magic(x1, y1);
}
int main(void)
{
    extern int n;
    scanf("%d", &n);
    magic(0, n/2);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        putchar('\n');
    }
    return 0;
}