#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkList;
//动态链表的学习2
int main()
{
    ElemType tmp;
    scanf("%d", &tmp);
    LinkList s, newS, head, cur, tmp2;
    ElemType count = 0;
    while(tmp != 666) {
        count++;
        newS = (LinkList)malloc(sizeof(Node));
        newS->data = tmp;
        newS->next = NULL;
        if (count == 1) {
            head = newS;
            s = newS;
        }
        else {
            s->next = newS;
            s = newS;
        }
        scanf("%d", &tmp);
    }
    s = head;
    while(s) {
        printf("%d\n", s->data);
        s = s->next;
    }
    cur = head;
    while(cur) {
        tmp2 = cur->next;
        free(cur);
        cur = tmp2;
    }
    return 0;
}