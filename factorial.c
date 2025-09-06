#include <stdio.h>
//4.2
//利用while或者for循环计算n！的值。
//提示：n！＝1*2*3…*n
int main()
{
    int n, num, m = 1;
    scanf("%d", &n);
    for (int num = 1; num <= n; num++)
    {
        m *= num;
    }
    printf("%d\n", m);
    return 0;
}