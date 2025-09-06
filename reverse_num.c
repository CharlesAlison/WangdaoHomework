#include <stdio.h>
//4.1
//输入一个整型数，判断是否是对称数，如果是，输出yes，否则输出no，不用考虑这个整型数过大，
//int类型存不下，不用考虑负值；
int main()
{
    int num;
    int reverse_num = 0;
    scanf("%d", &num);
    int num_re = num;//the value of "num" has changed in the 
    //following while circle(which is 0 in the end), so i need to 
    //define "num_re" to save the original value of 
    //"num" at the first time
    while(num > 0) {
        int a = num % 10;
        reverse_num = reverse_num * 10 + a;
        num = num / 10;
    }
    if(reverse_num == num_re) {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    return 0;
}