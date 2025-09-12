#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkList;
//动态链表的学习3，逆序输出
int main()
{
    ElemType tmp, count;
    scanf("%d", &tmp);
    LinkList s, newS, head, cur,  tmp2;
    count = 0;
    while(tmp != 666) {
        count++;
        newS = (LinkList)malloc(sizeof(Node));
        newS->data = tmp;
        newS->next = NULL;
        if (count == 1) {
            s = newS;
        }
        else {
            newS->next = s;
            s = newS;
        }
        scanf("%d", &tmp);
    }
    head = s;
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
