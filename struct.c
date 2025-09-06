#include <stdio.h>
#include <string.h>
//8.1
//输入一个学生的学号，姓名，性别，用结构体存储，通过scanf读取后，然后再通过printf打印输出
struct student {
    int num;
    char name[20];
    char gender;
};

int main()
{
    int num;
    char name[20];
    char gender;
    scanf("%d%s %c", &num, name, &gender);
    struct student s = {num, "", gender};
    strcpy(s.name, name);
    printf("%d %s %c\n", s.num, s.name, s.gender);
    return 0;
}