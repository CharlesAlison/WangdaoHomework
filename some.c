#include <stdio.h>

int main()
{
    int N;
    int count_even = 0;
    int count_odd = 0;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < N; i++) {
        if (a[i] % 2 == 0) {
            count_even++;
        }
        else {
            count_odd++;
        }
    }
    printf("%d %d", count_odd, count_even);
    return 0;
}