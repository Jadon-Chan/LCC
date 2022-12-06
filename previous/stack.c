#include <stdio.h>
#include <stdlib.h>

struct stack{
    char data[100000];
    int pointer;
};

void push(struct stack* shit, char ch)
{
    if (ch == '(')
        shit->data[shit->pointer] = ')';
    else if (ch == '[')
        shit->data[shit->pointer] = ']';
    else if (ch == '{')
        shit->data[shit->pointer] = '}';
    shit->pointer++;
}
char pop(struct stack* shit)
{
    shit->pointer--;
    return shit->data[shit->pointer];
}
int main(void)
{
    struct stack* shit = (struct stack*)malloc(sizeof(struct stack));
    shit->pointer = 0;
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        shit->pointer = 0;
        char ch;
        int flag = 1;
        while((ch = getchar()) != '\n')
        {
            if (ch == '(' || ch == '[' || ch == '{')
                push(shit, ch);
            else if (ch == ')' || ch == ']' || ch == '}')
            {
                char test = pop(shit);
                if (test != ch)
                {
                    flag = 0;
                }
            }
        }
        if (shit->pointer != 0)
            flag = 0;
        if (flag)
        {
            printf("True\n");
            continue;
        }
        else
        {
            printf("False\n");
            continue;
        }
    }
    return 0;
}   