#include <stdio.h>

struct stack{
    char data[1000];
    int pointer;
};

void push()
int main(void)
{
    struct stack haha;
    haha.pointer = 0;
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        char ch;
        int flag = 1;
        while((ch = getchar()) != '\n')
        {
            if (ch == '(' || ch == '[' || ch == '{')
                push(haha, ch);
            else if (ch == ')' || ch == ']' || ch == '}')
            {
                char test = pop(haha);
                if (test != ch)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
            printf("True\n");
        else
            printf("False\n");
    }
    return 0;
}   