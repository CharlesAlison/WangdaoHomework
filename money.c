#include <stdio.h>
//4.3
//某人想将手中的一张面值100元的人民币换成10元、5元、2元和1元面值的票子。
//要求换正好40张，且每种票子至少一张。问：有几种换法？
int main()
{
    int a, b, c, d, count = 0;
    for (a = 1; a < 10; a++) {
        for (b = 1; b < 19; b++) {
            for (c = 1; c < 37; c++) {
                d = 40 - a - b - c;
                if (d >= 1) {
                    if (10 * a + 5 * b + 2 * c + d == 100) {
                        count++;
                    }
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}