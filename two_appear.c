#include <stdio.h>
//5.1
//输入N个数（N小于等于100），输出数字2的出现次数；
// 解题提示：
// 整型数组读取5个整型数的方法如下：
// int a[100];
// for(int i=0;i<5;i++)
// {
// scanf("%d",&a[i]);
// }
int main()
{
    int num, count = 0;
    scanf("%d", &num);
    int a[100];
    for (int i = 0; i < num; i++) {
        scanf("%d", &a[i]);
    }
    for (int j = 0; j < num; j++) {
        if (a[j] == 2) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}