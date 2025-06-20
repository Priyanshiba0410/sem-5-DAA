#include <stdio.h>

int power(int base, int exponent) {
    if (exponent == 0)
        return 1;
    return base * power(base, exponent - 1);
}

int main() {
    int base, exponent, result;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter exponent (non-negative): ");
    scanf("%d", &exponent);

    if (exponent < 0) {
        printf("Exponent should be a non-negative integer.\n");
    } else {
        result = power(base, exponent);
        printf("%d^%d = %d\n", base, exponent, result);
    }

    return 0;
}

