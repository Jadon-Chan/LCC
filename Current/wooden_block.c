#include <stdio.h>
char canvas[1000][1000];
void block(int a, int c, int x, int y)
{
    canvas[x][y] = '+';
    canvas[x + 1][y - 1] = '/';
    for (int i = 1; i <= a; i++)
    {
        canvas[x][y - 2 * i] = '+';
        canvas[x][y - 2 * i + 1] = '-';
        canvas[x + 1][y - 2 * i - 1] = '/';
    }
    for (int i = 1; i <= c; i++)
    {
        canvas[x + 2 * i][y] = '+';
        canvas[x + 2 * i - 1][y] = '|';
        canvas[x + 2 * i + 1][y - 1] = '/';
    }
}
void cover(int a, int c, int x, int y)
{
    int m = x;
    for (int j = 0; j < c; j++)
    {
        for (int i = 1; i <= a; i++)
        {
            canvas[m][y - 2 * i] = '+';
            canvas[m][y - 2 * i + 1] = '-';
            canvas[m + 1][y - 2 * i] = '|';
        }
        canvas[m][y] = '+';
        canvas[m + 1][y] = '|';
        m += 2;
    }
    canvas[m][y] = '+';
    for (int i = 1; i <= a; i++)
    {
        canvas[m][y - 2 * i] = '+';
        canvas[m][y - 2 * i + 1] = '-';
    }
}
void paint_print(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    for (int i = 0; i <= 2 * b + 2 * c; i++)
        for (int j = 0; j <= 2 * a + 2 * b; j++)
            canvas[i][j] = ' ';
    int x = 0, y = 2 * a + 2 * b;
    for (int i = 0; i < b; i++)
    {
        block(a, c, x, y);
        x += 2;
        y -= 2;
    }
    cover(a, c, x, y);
    for (int i = 0; i <= 2 * b + 2 * c; i++)
    {
        for (int j = 0; j <= 2 * a + 2 * b; j++)
            putchar(canvas[i][j]);
        putchar('\n');
    }
}

int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        paint_print();
    return 0;
}