#include <stdio.h>

int main(void)
{
    char ch[100];
    int i = 0;
    while (1)
    {
        scanf("%d", ch+i);
        i++;
        if (ch[i-1] == 100)
            break;
    }
    return 0;
}