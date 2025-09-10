#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkList;
//静态链表的学习2
int main()
{
    LinkList s = (LinkList)malloc(sizeof(Node));
    scanf("%d", &(s->data));
    s->next = NULL;
    LinkList head, newS, cur, tmp;
    head = s;
    for (int i = 1; i <= 4; i++) {
        newS = (LinkList)malloc(sizeof(Node));
        scanf("%d", &(newS->data));
        s->next = newS;
        s = newS;
    }
    s = head;
    newS->next = NULL;
    while(s) {
        printf("%d\n", s->data);
        s = s->next;
    }
    cur = head;
    while (cur) {
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }

    return 0;
}