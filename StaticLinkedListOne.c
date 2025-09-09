#include <stdio.h>
//静态链表的学习
typedef struct node {
    int data;
    struct node *next;
} node;
int main()
{
    node a1 = {1, NULL};
    node a2 = {2, NULL};
    node a3 = {3, NULL};
    node a4 = {4, NULL};
    node a5 = {5, NULL};
    a5.next = &a2;
    a2.next = &a4;
    a4.next = &a3;
    a3.next = &a1;
    node *p;
    p = &a5;
    printf("%d\n", p->data);
    printf("%d\n", p->next->data);
    while(p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    return 0;
}