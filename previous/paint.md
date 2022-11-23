# Paint.c

```c
#include <stdio.h>
#include <math.h>

char canvas[3000][3000];

void square(int n, int x, int y)
{
    for (int i = x; i < x+(int)pow(2, n-1); i++)
        for (int j = y; j < y+(int)pow(2, n-1); j++)
            canvas[i][j] = ' ';
}
void paint(int n, int x, int y)
{
    square(n, x, y);
    square(n, x, y+3*(int)pow(2, n-1));
    if (n == 1)
    {
        canvas[x][y+1] = canvas[x+1][y] = '/';
        canvas[x][y+2] = canvas[x+1][y+3] = '\\';
        canvas[x+1][y+1] = canvas[x+1][y+2] = '_';
    }
    else
    {
        paint(n-1, x+(int)pow(2, n-1), y);
        paint(n-1, x, y+(int)pow(2, n-1));
        paint(n-1, x+(int)pow(2, n-1), y+(int)pow(2, n));
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    paint(n, 0, 0);
    for (int i = 0; i < (int)pow(2, n); i++)
    {
        for (int j = 0; j < (int)pow(2, n+1); j++)
            putchar(canvas[i][j]);
        putchar('\n');
    }
    return 0;
}
```
