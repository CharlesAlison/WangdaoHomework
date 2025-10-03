#include <stdio.h>
#define Maxsize 50
typedef int ElemType;

typedef struct{
    ElemType data[Maxsize];
    int length;
} SqList;

bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length) {
        return false;
    }
    if (L.length == Maxsize) {
        return false;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length) {
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}
int main()
{
    SqList L;
    bool ret1, ret2;
    ElemType e1, e2;
    int p;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    scanf("%d%d", &e1, &p);
    ret1 = ListInsert(L, 2, e1);
    if (ret1) {
        PrintList(L);
    }
    else {
        printf("false");
    }
    ret2 = ListDelete(L, p, e2);
    if (ret2) {
        PrintList(L);
    }
    else {
        printf("false");
    }

    return 0;
}










