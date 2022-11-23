#include <stdio.h>
#include <stdbool.h>

int main()
{
    int num[53] = {1,0};
    int length;
    char ch;
    int max = 0;
    int count = 0;
    int last;

    scanf("%d", &length);
    getchar();
    for (int i = 1; i <= length; i++)
    {
        if ((ch = getchar()) >= 'a')
            num[(ch - 'a' + 1) * 2 - 1]++;
        else 
            num[(ch - 'A' + 1) * 2]++;
    }
    for (int i = 1; i <= 52; i++)
        if (num[i] > max)
            max = num[i];
    for (int line = 1; line <= max; line++)
    {
        for (int i = 1; i <= 52; i++)
        {
            if (i % 2 == 1 && num[i] != 0 && num[i-1] != 0 && i > 1)
            {
                putchar(' ');
                count++;
            }
            if (num[i] != 0)
            {
                    if (num[i] + line > max)
                        putchar('=');
                    else
                        putchar(' ');
            }
            if ((num[i + 1] == 0 && num[i] != 0)) 
            {
                putchar(' ');
                count++;
            }
        }
        putchar('\n');
    }
    for(int i = 1; i <= 52; i++)
    {
        if (num[i] != 0)
            count++;
    }
    for (int i = 52; i >= 1; i--)
    {
        if (num[i] != 0)
        {
            last = i;
            break;
        }
    }
    for (int i = 1; i <= 52; i++)
    {
        if (i % 2 == 1 && num[i] != 0 && num[i-1] != 0 && i > 1)
            putchar('-');
        if (num[i] != 0)
            putchar('-');
        if ((num[i + 1] == 0 && num[i] != 0) && i != last) 
            putchar('-');
    }
    putchar('\n');
    for (int i = 1; i <= 52; i++)
    {
        if (i % 2 == 1 && num[i] != 0 && num[i-1] != 0 && i > 1)
            putchar(' ');
        if (num[i] != 0)
        {
            if (i % 2 == 1)
                printf("%c", (i - 1) / 2 + 'a');
            else
                printf("%c", i / 2 + 'A' - 1);
        }
        if ((num[i + 1] == 0 && num[i] != 0)) 
            putchar(' ');
    }
    return 0;
}