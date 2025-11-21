#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n + 1];
    if(n % 2 == 0) {
        for (int i = 1; i <= n / 2; i++) {
            a[i] = i; 
        }
        for (int j = n / 2 + 1; j <= n; j++) {
            a[j] = n / 2 + (-1) * j;
        }
    }
    else {
        a[n / 2 + 1] = 0;
        for (int i = 1; i <= n / 2; i++) {
            a[i] = i;
        }
        for (int j = (n + 1) / 2; j <= n; j++) {
            a[j] = n / 2 + (-1) * j + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}