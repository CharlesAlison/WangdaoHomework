#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void list_insert_head(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L ->next = NULL;
    ElemType x;
    while(scanf("%d", &x) && x != 9999) {
        LinkList s;
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
    }
}

void list_insert_tail(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LinkList r;
    r = L;
    ElemType x;
    while(scanf("%d", &x) && x != 9999) {
        LinkList s;
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL;
        r->next = s;
        r = s;
    }
}

void PrintList(LinkList L)

{

L=L->next;

while(L!=NULL)

{

printf("%d",L->data);//打印当前结点数据

L=L->next;//指向下一个结点

if(L!=NULL)

{

printf(" ");

}

}

printf("\n");

}



int main()
{
    LinkList L1, L2;
    list_insert_head(L1);
    list_insert_tail(L2);
    PrintList(L1);
    PrintList(L2);

    return 0;
}

