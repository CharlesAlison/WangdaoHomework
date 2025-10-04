#include <stdio.h>
#define MaxSize 50
typedef int ElemType;
typedef struct 
{
    ElemType data[MaxSize];
    int length;
} SqList;

bool ListInsert(SqList &L, int i, ElemType e) 
{
    if (i < 1 || i > L.length + 1) 
    {
        return false;
    }
    if (L.length == MaxSize) 
    {
        return false;
    }
    for (int j = L.length; j >= i; j--) 
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length) {
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

void ListPrint(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

int main()
{
    SqList L;
    int i, j, pos;
    bool ret1, ret2;
    ElemType e1, e2, e3;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    scanf("%d%d%d%d", &i, &e1, &j, &e3);
    ret1 = ListInsert(L, i, e1);
    if (ret1)
    {
        ListPrint(L);
    }
    else
    {
        printf("false\n");
    }
    ret2 = ListDelete(L, j, e2);
    if (ret2)
    {
        ListPrint(L);
    }
    else
    {
        printf("false\n");
    }
    printf("%d\n", e2);
    pos = LocateElem(L, e3);
    if (pos)
    {
        printf("%d\n", pos);
    }
    else
    {
        printf("false");
    }
    return 0;
}