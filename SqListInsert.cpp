#include <stdio.h>
//10.3 顺序表的初始化及插入操作实战
#define Maxsize 50
typedef int ElemType;

typedef struct{
    ElemType data[Maxsize];
    int length;
} SqList;

bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) {
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

void PrintList(SqList L) {
    int i;
    for (int i = 0; i < L.length; i++) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

int main()
{
    SqList L;
    bool ret;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    ret = ListInsert(L, 2, 60);
    if (ret) {
        printf("list insert success!\n");
        PrintList(L);
    }
    else {
        printf("list insert error!\n");
    }
    return 0;
}














