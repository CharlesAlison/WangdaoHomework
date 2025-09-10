#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkList;

int main()
{
    LinkList s = (LinkList)malloc(sizeof(Node));
    scanf("%d", &(s->data));
    s->next = NULL;
    LinkList head, newS;
    head = s;
    for (int i = 1; i <= 4; i++) {
        newS = (LinkList)malloc(sizeof(LinkList));
        scanf("%d", &(newS->data));
        s->next = newS;
        s = newS;
    }
    s = head;
    newS->next = NULL;
    while(s) {
        printf("%d\t", s->data);
        s = s->next;
    }
    free(s);
    free(newS);
    return 0;
}