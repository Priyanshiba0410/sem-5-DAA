#include <stdio.h>

int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num < 0) {
        num = -num;
    }

    printf("Sum of digits: %d\n", sumOfDigits(num));

    return 0;
}

