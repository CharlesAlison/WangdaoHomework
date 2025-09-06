#include <stdio.h>
//3.1
//判断某个年份是不是闰年，如果是闰年，请输出“yes”，否则请输出“no”
int main()
{
    int y;
    scanf("%d", &y);
    if(y % 4 == 0 && y & 100 != 0||y % 400 == 0) {
        printf("yes");
    }
    else {
        printf("no");
    }
    return 0;
}