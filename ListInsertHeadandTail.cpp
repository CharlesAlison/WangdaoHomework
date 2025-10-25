#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void ListHeadInsert(LinkList &L)//input 1, 2, 3, 999
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    ElemType e;
    scanf("%d", &e);
    LinkList s;
    while(e != 9999) {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = e;
        s->next = L->next;
        L->next = s;
        scanf("%d", &e);
    }
}

void ListTailInsert(LinkList &L) 
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    ElemType e;
    scanf("%d", &e);
    LinkList s, r = L;
    while(e != 9999) {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = e;
        r->next = s;
        r = s;
        scanf("%d", &e);
    }
    r->next = NULL;
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
    LinkList L, S;
    ListHeadInsert(L);
    ListTailInsert(S);
    PrintList(L);
    PrintList(S);
    return 0;
}
