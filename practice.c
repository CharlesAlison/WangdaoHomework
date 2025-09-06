#include <stdio.h>
#include <stdlib.h>
//8.2 practice
typedef struct student {
    int num;
    float score;
} stu;
void change(stu *q)
{
    q->num = 1002;
    q->score = 100.0;
}

int main()
{
    stu *p = (stu *)malloc(sizeof(stu));
    p->num = 1001;
    p->score = 98.5;
    change(p);
    printf("num = %d score = %d\n", p->num, p->score);
    return 0;
}