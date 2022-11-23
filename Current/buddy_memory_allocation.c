#include <stdio.h>
#include <math.h>

struct Node{
    int size;
    int id = 0;
    struct Node* next = NULL;
};

void allocate(int id, int length, struct Node* head)
{
    int power = 0;
    while ((int)(pow(2, power)+0.5) < length)
        power++;
    struct Node* ptr = head;
    while (ptr)
    {
        if (ptr->size == power && ptr->id == 0)
        {
            ptr->id = id;
            break;
            return;
        }
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        ptr = head;
        while (ptr)
        {
            if (ptr->size > power && ptr->id == 0)
            {
                struct Node* child = (struct Node*)malloc(sizeof(struct Node));
                ptr->size -= 1;
                child->next = ptr->next;
                ptr->next = child;
                child->id = 0;
                child->size = ptr->size;
                break;
            }
            ptr = ptr->next;
        }
        allocate(id, length, head);
    }
}

void show(struct Node* head)
{
    while (head)
    {
        printf("%d ", head->id);
        head = head->next;
    }
    putchar('\n');
}
int main(void)
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    int instruc;
    scanf("%d %d", &(head->size), &instruc);
    head->id = 0;
    head->next = NULL;
    for (int i = 0; i < instruc; i++)
    {
        getchar();
        char ch = getchar();
        if (ch == 'Q')
            show(head);
        else if (ch == 'A')
        {
            int id, length;
            scanf(" %d %d", &id, &length);
            allocate(id, length, head);
        }
    }
    return 0;
}