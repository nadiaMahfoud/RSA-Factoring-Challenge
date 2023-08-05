#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p;
    int q;
} Factors;

Factors factorize(int number) {
    Factors factors = {-1, -1};
    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            factors.p = i;
            factors.q = number / i;
            break;
        }
    }
    return factors;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    FILE *file = fopen(input_file, "r");
    if (file == NULL) {
        printf("File not found: %s\n", input_file);
        return 1;
    }

    int number;
    while (fscanf(file, "%d", &number) != EOF) {
        Factors factors = factorize(number);
        if (factors.p != -1 && factors.q != -1) {
            printf("%d=%d*%d\n", number, factors.p, factors.q);
        } else {
            printf("%d is prime\n", number);
        }
    }

    fclose(file);
    return 0;
}

