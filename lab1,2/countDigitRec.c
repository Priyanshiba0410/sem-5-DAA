#include <stdio.h>

int countDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return 1 + countDigits(n / 10);
}

void main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("Number of digits: 1\n");
    } else {
        if (num < 0) {
            num = -num;  
        }
        printf("Number of digits: %d\n", countDigits(num));
    }

    return 0;
}

